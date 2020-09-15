var CONST = require("./const");

module.exports = {
  title: `Today I Learned`,
  description: `오늘 공부한건 오늘 적자`,
  base: "/TIL/",
  dest: "build",
  head: [
    ['link', {
      rel: 'icon',
      href: '/logo.png'
    }]
  ],
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
        title: "Linux",
        children: CONST.Linux_list
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
        title: "Docker",
        children: CONST.Docker_list
      },
      {
        title: "Travis CI",
        children: CONST.Travis_list
      },
      {
        title: "Vuepress",
        children: CONST.Vuepress_list
      },
      {
        title: "Software_Engineering",
        children: CONST.SE_list
      },
      {
        title: "Distribute_Computing",
        children: CONST.Distribute_list
      },
      {
        title: "Open_Source_Software",
        children: CONST.OSS_list
      },
      {
        title: "Program_Language",
        children: CONST.PL_list
      },
      {
        title: "Data_Communication",
        children: CONST.DC_list
      },
      {
        title: "Computer_Network",
        children: CONST.Network_list
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