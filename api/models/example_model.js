const database = require('../database');//..tarkoitaa että perutetaan hakemistossa yksi, päätteitä ei laiteta, esim .js tai .txt

const example_sql = {

    getAllPersons: function(callback){
        return database.query('select * from person', 
        callback);
    },

    getOnePerson: function(id, callback){
        return database.query('select * from person where id_person=?',[id], 
        callback);//yllä sidotaan id, olisi voinut myös kirjoittaa ...person=' + id), mutta se on turvallisuus riski?
    },
    getFullName: function(id, callback){
        return database.query('select CONCAT(fname," ",lname) AS fullname from person where id_person=?',[id],
        callback)
    }
};

module.exports = example_sql;//täällä exportataan, example.js vastaanotetaan