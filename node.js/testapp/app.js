//require the mongoClient from mongodb module
let MongoClient = require('mongodb').MongoClient;

//mongodb configs
let connectionUrl = 'mongodb://localhost:27017/myproject';
let sampleCollection = 'chapters';

const dbName = 'myproject';

//We need to insert these chapters into mongoDB
var chapters = [{
    'Title': 'Snow Crash',
    'Author': 'Neal Stephenson'
},{
    'Title': 'Snow Crash',
    'Author': 'Neal Stephenson'
}];

let g = {useNewUrlParser: true};

MongoClient.connect(connectionUrl, g, function(err, client) {

  console.log("Connected correctly to server");

  const db = client.db(dbName);

  // Get some collection
  var collection = db.collection(sampleCollection);

  collection.insert(chapters,function(error,result){
    //here result will contain an array of records inserted
    if(!error) {
      console.log("Success :"+result.ops.length+" chapters inserted!");
    } else {
      console.log("Some error was encountered!");
    }
    client.close();
  });
});