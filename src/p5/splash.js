// P_4_3_1_01
//
// Generative Gestaltung – Creative Coding im Web
// ISBN: 978-3-87439-902-9, First Edition, Hermann Schmidt, Mainz, 2018
// Benedikt Groß, Hartmut Bohnacker, Julia Laub, Claudius Lazzeroni
// with contributions by Joey Lee and Niels Poldervaart
// Copyright 2018
//
// http://www.generative-gestaltung.de
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * pixel mapping. each pixel is translated into a new element
 *
 * MOUSE
 * position x/y        : various parameters (depending on draw mode)
 *
 * KEYS
 * 1-9                 : switch draw mode
 * s                   : save png
 */

// [@bs.val] [@bs.module("./p5.min.js","p5")] external createCanvas : (int, int, string) => unit = "createCanvas";

export default function sketch = (p) => {
  var drawMode = 1;

  var img;

  p.preload = () => {
    img = p.loadImage('data/pic.png');
  }

  p.setup = ()=> {
    p.createCanvas(603, 873, p.WEBGL);
    p.print(img.width + ' • ' + img.height);
  }

  p.myCustomRedrawAccordingToNewPropsHandler = (props) => {
  }

  p.draw = () => {
    p.background(255);

    var mouseXFactor = map(mouseX, 0, width, 0.05, 1);
    var mouseYFactor = map(mouseY, 0, height, 0.05, 1);

    for (var gridX = 0; gridX < img.width; gridX++) {
      for (var gridY = 0; gridY < img.height; gridY++) {
        // grid position + tile size
        var tileWidth = width / img.width;
        var tileHeight = height / img.height;
        var posX = tileWidth * gridX;
        var posY = tileHeight * gridY;

        // get current color
        img.loadPixels();
        var c = p.color(img.get(gridX, gridY));
        // greyscale conversion
        var greyscale = p.round(red(c) * 0.222 + green(c) * 0.707 + blue(c) * 0.071);

        switch (drawMode) {
        case 1:
          // greyscale to stroke weight
          var w1 = map(greyscale, 0, 255, 15, 0.1);
          p.stroke(0);
          p.strokeWeight(w1 * mouseXFactor);
          p.line(posX, posY, posX + 5, posY + 5);
          break;
        case 2:
          // greyscale to ellipse area
          p.fill(0);
          p.noStroke();
          var r2 = 1.1284 * sqrt(tileWidth * tileWidth * (1 - greyscale / 255));
          r2 *= mouseXFactor * 3;
          p.ellipse(posX, posY, r2, r2);
          break;
        case 3:
          // greyscale to line length
          var l3 = p.map(greyscale, 0, 255, 30, 0.1);
          l3 *= mouseXFactor;
          p.stroke(0);
          p.strokeWeight(10 * mouseYFactor);
          p.line(posX, posY, posX + l3, posY + l3);
          break;
        case 4:
          // greyscale to rotation, line length and stroke weight
          p.stroke(0);
          var w4 = p.map(greyscale, 0, 255, 10, 0);
          p.strokeWeight(w4 * mouseXFactor + 0.1);
          var l4 = p.map(greyscale, 0, 255, 35, 0);
          l4 *= mouseYFactor;
          p.push();
          p.translate(posX, posY);
          p.rotate(greyscale / 255 * PI);
          p.line(0, 0, 0 + l4, 0 + l4);
          p.pop();
          break;
        case 5:
          // greyscale to line relief
          var w5 = p.map(greyscale, 0, 255, 5, 0.2);
          p.strokeWeight(w5 * mouseYFactor + 0.1);
          // get neighbour pixel, limit it to image width
          var c2 = p.color(img.get(min(gridX + 1, img.width - 1), gridY));
          p.stroke(c2);
          var greyscale2 = floor(red(c2) * 0.222 + green(c2) * 0.707 + blue(c2) * 0.071);
          var h5 = 50 * mouseXFactor;
          var d1 = map(greyscale, 0, 255, h5, 0);
          var d2 = map(greyscale2, 0, 255, h5, 0);
          p.line(posX - d1, posY + d1, posX + tileWidth - d2, posY + d2);
          break;
        case 6:
          // pixel color to fill, greyscale to ellipse size
          var w6 = map(greyscale, 0, 255, 25, 0);
          p.noStroke();
          p.fill(c);
          p.ellipse(posX, posY, w6 * mouseXFactor, w6 * mouseXFactor);
          break;
        case 7:
          p.stroke(c);
          var w7 = map(greyscale, 0, 255, 5, 0.1);
          p.strokeWeight(w7);
          p.fill(255, 255 * mouseXFactor);
          p.push();
          p.translate(posX, posY);
          p.rotate(greyscale / 255 * PI * mouseYFactor);
          p.rect(0, 0, 15, 15);
          p.pop();
          break;
        case 8:
          p.noStroke();
          p.fill(greyscale, greyscale * mouseXFactor, 255 * mouseYFactor);
          p.rect(posX, posY, 3.5, 3.5);
          p.rect(posX + 4, posY, 3.5, 3.5);
          p.rect(posX, posY + 4, 3.5, 3.5);
          p.rect(posX + 4, posY + 4, 3.5, 3.5);
          break;
        case 9:
          p.stroke(255, greyscale, 0);
          p.noFill();
          p.push();
          p.translate(posX, posY);
          p.rotate(greyscale / 255 * PI);
          p.strokeWeight(1);
          p.rect(0, 0, 15 * mouseXFactor, 15 * mouseYFactor);
          var w9 = map(greyscale, 0, 255, 15, 0.1);
          p.strokeWeight(w9);
          p.stroke(0, 70);
          p.ellipse(0, 0, 10, 5);
          p.pop();
          break;
        }
      }
    }
  }

  // function keyReleased() {
  //   if (key == 's' || key == 'S') saveCanvas(gd.timestamp(), 'png');

  //   // change draw mode
  //   if (key == '1') drawMode = 1;
  //   if (key == '2') drawMode = 2;
  //   if (key == '3') drawMode = 3;
  //   if (key == '4') drawMode = 4;
  //   if (key == '5') drawMode = 5;
  //   if (key == '6') drawMode = 6;
  //   if (key == '7') drawMode = 7;
  //   if (key == '8') drawMode = 8;
  //   if (key == '9') drawMode = 9;
  // }
};


  // Line 50:   'map' is not defined     no-undef
  // Line 50:   'mouseX' is not defined  no-undef
  // Line 50:   'width' is not defined   no-undef
  // Line 51:   'map' is not defined     no-undef
  // Line 51:   'mouseY' is not defined  no-undef
  // Line 51:   'height' is not defined  no-undef
  // Line 56:   'width' is not defined   no-undef
  // Line 57:   'height' is not defined  no-undef
  // Line 65:   'red' is not defined     no-undef
  // Line 65:   'green' is not defined   no-undef
  // Line 65:   'blue' is not defined    no-undef
  // Line 70:   'map' is not defined     no-undef
  // Line 79:   'sqrt' is not defined    no-undef
  // Line 100:  'PI' is not defined      no-undef
  // Line 109:  'min' is not defined     no-undef
  // Line 111:  'floor' is not defined   no-undef
  // Line 111:  'red' is not defined     no-undef
  // Line 111:  'green' is not defined   no-undef
  // Line 111:  'blue' is not defined    no-undef
  // Line 113:  'map' is not defined     no-undef
  // Line 114:  'map' is not defined     no-undef
  // Line 119:  'map' is not defined     no-undef
  // Line 126:  'map' is not defined     no-undef
  // Line 131:  'PI' is not defined      no-undef
  // Line 148:  'PI' is not defined      no-undef
  // Line 151:  'map' is not defined     no-undef