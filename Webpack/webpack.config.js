const HtmlWebpackPlugin = require('html-webpack-plugin');

module.exports = {
  entry: './app.js',
  mode: 'production',
  output: {
      path: __dirname + '/dist',
      filename: 'app@production.js'
  },
	module: {
    rules: [
      { 
      	test: /\.wasm$/,
	      type: 'webassembly/experimental'
      }
    ]
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: __dirname + '/index.html'
    })
  ]
};
