//pitää ensin luoda muuttuja joko sanalla var tai const, const on suositeltu (const tyyppistä ei voi muuttaa kesken koodin)
const express = require('express');
const router = express.Router();//Tässä ei ole pakko olla router muuttujan nimenä
const example_sql = require('../models/example_model');//viittaus tietokantaan, eli toteutus? .js kansio?, vastaanotetaan

router.get('/allpersons',//aletaan tekemään metodia, get metodia käytetään
    function(request,response){//requestia ei käytetä kun yllä ei vaadita mitään parametrejä
        example_sql.getAllPersons(function(err, dbResult){//yllä näkyy, viitataan example_sql example_model tiedostoon mistä löytyy getAllPersons toteutus
            if(err){//koska on asynkroninen funktio pitää yllä taas viitata function ja annetaan sille kaksi parametria err ja dbResult tässä
                response.json(err);//jos tietokannassa tulee virhe lähetetään tämä response err
            }
            else{
                response.json(dbResult);//jos ei, lähetetään dbResult
            }
        }
        )
    }
);



module.exports = router;//tässä vastaava muuttujan nimi kuin ylllä olevassa const muuttujassa(käytetään siis sitä)
