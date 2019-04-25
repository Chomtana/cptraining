const { spawn } = require('child_process')

var firstPart = 0;
var secondPart = 0;

var graderExec = "";
var graderArgs = [];
var solExec = "";
var solArgs = [];

process.argv.forEach(function (val, index, array) {
  if (val == "--") {
    if (firstPart == 0 && secondPart == 0) {
      firstPart = 1;
      secondPart = 0;
    } else {
      firstPart = 2;
      secondPart = 1;
    }
  } else {
    if (firstPart == 1 && secondPart == 0) {
      graderExec = val;
      firstPart = 2;
    } else if (firstPart == 2 && secondPart == 0) {
      graderArgs.push(val); 
    } else if (secondPart == 1) {
      solExec = val;
      secondPart = 2;
    } else if (secondPart == 2) {
      solArgs.push(val);
    }
  }
});

console.log(graderExec);
console.log(graderArgs);
console.log(solExec);
console.log(solArgs);

//const child = spawn('ls', ['-a', '-l']);

