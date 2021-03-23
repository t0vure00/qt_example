const database = require('../database');//..tarkoitaa että perutetaan hakemistossa yksi, päätteitä ei laiteta, esim .js tai .txt

const example_sql = {

    getAllPersons: function(callback){
        return database.query('select * from person', 
        callback);
    }
};

module.exports = example_sql;//täällä exportataan, example.js vastaanotetaan