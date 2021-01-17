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

let cnt = 0;

async function getDrawnTeam(year) {
  let pages = 1;
  for (let team1 = 0, team2 = 0; team1 < 10; team1++, team2++) {
    const result = await axios.get(
      `https://jsonmock.hackerrank.com/api/football_matches?year=${year}&team1goals=${team1}&team2goals=${team2}&page=${pages}`
    );
    cnt += result.data.total;
  }
}

async function main() {
  const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

  const year = parseInt(readLine().trim(), 10);

  await getDrawnTeam(year);
  ws.write(cnt + "\n");

  ws.end();
}
