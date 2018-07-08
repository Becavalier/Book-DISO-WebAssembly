const HtmlWebpackPlugin = require('html-webpack-plugin');

module.exports = {
  entry: './app.js',
  mode: 'production',
  output: {
      path: __dirname + '/dist',
      filename: 'app@production.js'
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: __dirname + '/index.html'
    })
  ]
};
