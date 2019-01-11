const path = require('path');

module.exports = {
  target: 'web',
  entry: './src/Day3web.bs.js',
  output: {filename: 'main.js', path: path.resolve(__dirname, 'dist')}
};