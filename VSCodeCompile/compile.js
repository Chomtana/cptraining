const chalk = new require('chalk').constructor({level: 2});
const config = require('./config');
const { exec } = require('child_process');
const escapeStringRegexp = require('escape-string-regexp');
const fs = require("fs");


if (process.argv[2]) {
    var filename = process.argv[2];
    var needcompile = true;
    
    try {
        var oldcontent = fs.readFileSync(filename+".cache").toString();
        var newcontent = fs.readFileSync(filename).toString();
        //console.log(oldcontent == newcontent);
        if (oldcontent == newcontent) {
            needcompile = false;
        }
    } catch (exception) {
        
    }
    
    if (!needcompile) {
        console.error(chalk.yellowBright("Same code as previous ....\nRunning ...."));
        process.exit(0);
    } 
    
    fs.writeFileSync(filename+".cache", fs.readFileSync(filename));
    
    console.error(chalk.yellowBright("Compiling ....\n"));
    
    exec('g++ '+config.arg+' -o '+filename+'.exe '+filename,(error, stdout, stderr) => {
        if (error) {
            //mang smart mark
            //if mang compile error -> mang ja tob wa error (run tong ne)
            //if mun compile success -> mun kor ja mai run tong ne
            console.error(chalk.magentaBright(`************ Compile Error ************\n`));
        }
        //console.log(`stdout: ${stdout}`);
        try {
            var regex_mainfile = new RegExp(escapeStringRegexp(filename)+"([\\s\\S]*?)\\^+\\~*","g");
            //var regex_mainfile = /(.*)/g;
            var match_mainfile = stderr.match(regex_mainfile).filter((val)=>{
                return val.indexOf(config.mingw_path) == -1;
            });
            var errmsg = match_mainfile.join('\n--------------------------------------------------\n');
            console.log(chalk.magentaBright(`${errmsg}`));
        } catch (exception) {
            
        }
        if (error) {
            console.error(chalk.magentaBright(`\n************ Compile Error ************`));
            fs.unlinkSync(filename+".cache")
            process.exit(1);
        } else {
            console.error(chalk.greenBright(`************ Compile Success ************`));
        }
    });
}