var CONST = require("./const");

module.exports = {
  title: `Today 20h Learned`,
  description: `Today I Learned`,
  base: "/TIL/",
  dest: "build",
  head: [],
  themeConfig: {
    sidebar: [
      {
        title: "Algorithm",
        children: CONST.AlgorithmList
      },
      {
        title: "Operating_System",
        children: CONST.OS_List
      },
      {
        title: "JavaScript",
        children: CONST.JS_list
      },
      {
        title: "Express",
        children: CONST.Express_list
      },
      {
        title: "DataBase",
        children: CONST.DB_list
      },
      {
        title: "Program_Language",
        children: CONST.PL_list
      },
      {
        title: "Data_Communication",
        children: CONST.DC_list
      }
    ],
    nav: [
      {
        text: "GitHub",
        link: "https://github.com/lee20h/",
      },
    ],
  },
  plugins: [["@vuepress/back-to-top"],
            ["image"]
            ]
};