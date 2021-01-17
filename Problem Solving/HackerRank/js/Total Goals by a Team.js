"use strict";

const fs = require("fs");

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on("end", function () {
  inputString = inputString.split("\n");

  main();
});

function readLine() {
  return inputString[currentLine++];
}

/*
 * Complete the 'getTotalGoals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING team
 *  2. INTEGER year
 */

const axios = require("axios");

let pages = 1;
let goals = 0;

async function getAwayTeamGoals(team, year) {
  pages = 1;
  do {
    const result = await axios.get(
      `https://jsonmock.hackerrank.com/api/football_matches?year=${year}&team2=${team}&page=${pages}`
    );
    let per_page = result.data.per_page;
    const total_pages = result.data.total_pages;
    if (total_pages === 0) return;

    if (total_pages !== 1 && total_pages === pages) {
      per_page = result.data.total - (total_pages - 1) * per_page;
    } else if (total_pages === 1) {
      per_page = result.data.total;
    }
    let idx = 0;
    while (true) {
      if (idx == per_page) {
        break;
      }

      goals += result.data.data[idx++].team2goals * 1;
    }

    if (pages == result.data.total_pages) {
      break;
    }
    pages++;
  } while (true);
}

async function getHomeTeamGoals(team, year) {
  pages = 1;
  do {
    const result = await axios.get(
      `https://jsonmock.hackerrank.com/api/football_matches?year=${year}&team1=${team}&page=${pages}`
    );
    let per_page = result.data.per_page;
    const total_pages = result.data.total_pages;
    if (total_pages === 0) return;

    if (total_pages !== 1 && total_pages === pages) {
      per_page = result.data.total - (total_pages - 1) * per_page;
    } else if (total_pages === 1) {
      per_page = result.data.total;
    }
    console.log(result.data.total);
    console.log(total_pages);
    console.log(per_page);
    let idx = 0;
    while (true) {
      if (idx == per_page) {
        break;
      }

      goals += result.data.data[idx++].team1goals * 1;
    }
    if (pages === result.data.total_pages) {
      break;
    }
    pages++;
  } while (true);
}

async function main() {
  const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

  const team = readLine();

  const year = parseInt(readLine().trim(), 10);

  await getHomeTeamGoals(team, year);
  await getAwayTeamGoals(team, year);
  ws.write(goals + "\n");

  ws.end();
}
