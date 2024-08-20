#!/usr/bin/node
const request = require('request');

function fetchCharacter(url) {
    request(url, function (error, response, body) {
        if (error) {
            console.error('Error:', error);
            return;
        }
        const character = JSON.parse(body);
        console.log(character.name);

        // If the next URL is present, fetch the next character
        if (character.next) {
            fetchCharacter(character.next);
        }
    });
}

function fetchMovieCharacters(movieId) {
    const url = `https://swapi.dev/api/films/${movieId}/`;
    request(url, function (error, response, body) {
        if (error) {
            console.error('Error:', error);
            return;
        }
        const movie = JSON.parse(body);
        movie.characters.forEach(characterUrl => {
            fetchCharacter(characterUrl);
        });
    });
}

const movieId = process.argv[2];
fetchMovieCharacters(movieId);
