#!/usr/bin/node
/*
    Write a script that prints all characters of a Star Wars movie:

    The first positional argument passed is the Movie ID -
    example: 3 = “Return of the Jedi”
    Display one character name per line in the same order
    as the “characters” list in the /films/ endpoint
    You must use the Star wars API
    You must use the request module
*/

const args = process.argv.slice(2);
if (args < 1) {
  console.log('Error');
  process.exit(1);
}

const episode = args[0];
const url = 'https://swapi-api.hbtn.io/api/films/' + episode;
const request = require('request');
let characters = [];
request(url, (err, resp, body) => {
  if (err || resp.statusCode !== 200) console.log(err);
  else characters = JSON.parse(body).characters;
  const size = Object.keys(characters).length;
  for (let i = 0; i < size; i++) {
    request(characters[i], (erro, respo, bodys) => {
      if (erro || respo.statusCode !== 200) console.log(erro);
      else {
        console.log(JSON.parse(bodys).name);
      }
    });
  }
});
