#!/usr/bin/node
/*
  Write a script that prints the number of movies where the character
  "Wedge Antilles" is present.
  The first argument is the API URL of the Star wars API:
  http://swapi.co/api/movies/

  https://swapi-api.hbtn.io/api/

  Wedge Antilles is character ID 18
  You must use the module request
*/

const args = process.argv.slice(2);
if (args < 1) {
  console.log('Error');
  process.exit(1);
}

const episode = args[0];
console.log(episode)
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
