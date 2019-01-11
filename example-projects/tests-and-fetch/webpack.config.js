const path = require('path');

module.exports = {
  target: 'web',
  entry: './src/FetchExcercise.bs.js',
  output: {filename: 'main.js', path: path.resolve(__dirname, 'dist')}
};