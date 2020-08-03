var CONST = require("./const");

module.exports = {
    title: `Today 20h Learned`,
    description: `Today I Learned`,
    base: "/TIL/",
    dest: 'build',
    head: [
        
    ],
    themeConfig: {
        sidebar: [
            {
                title: 'Algorithm',
                children: CONST.AlgorithmList
            },
            {
                title: 'Operating System',
                children: CONST.OSList
            },
            {
                title: 'Program_Language',
                children: CONST.PLlist
            }
        ],

          nav: [{
              text: 'GitHub',
              link: 'https://github.com/lee20h/'
            }
          ]
        },
    plugins: ['@vuepress/back-to-top'],
    configureWebpack: {
        resolve: {
            alias: {
                '@algorithm': 'public/img/algorithm'
            }
        }
    }
}