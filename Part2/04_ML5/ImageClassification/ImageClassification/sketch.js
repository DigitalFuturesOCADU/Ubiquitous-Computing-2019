// Copyright (c) 2018 ml5
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

/* ===
ml5 Example
Image classification using MobileNet and p5.js
This example uses a callback pattern to create the classifier
=== */

// Initialize the Image Classifier method with MobileNet. A callback needs to be passed.
let classifier;

// A variable to hold the image we want to classify
let img;

let howConfident;
let whatIsIt;


function preload() {
  classifier = ml5.imageClassifier('MobileNet');
  img = loadImage('images/bird.jpg');
}

function setup() {
  createCanvas(400, 400);
  classifier.classify(img, gotResult);
  
}

function draw()
{
//image(img, 0, 0);
background(255);
textSize(10);
textAlign(CENTER);

fill(255,0,0,map(howConfident,0,1,0,255));
text(whatIsIt,width/2,height/2);

}



// A function to run when we get any errors and the results
function gotResult(error, results) {
  // Display error in the console
  if (error) {
    console.error(error);
  }
  whatIsIt = results[0].label;
  howConfident = results[0].confidence;
  // The results are in an array ordered by confidence.
  //console.log(results);
  //createDiv('Label: ' + results[0].label);
  //createDiv('Confidence: ' + nf(results[0].confidence, 0, 2));
}
