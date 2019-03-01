type canvasRenderingContext2D;

type ctx = canvasRenderingContext2D;

type canvasElement;

type imageData = {
  width: int,
  height: int,
  data: array(int)
};

let getById: string => canvasElement = [%bs.raw
  {|function(arg) {
    return document.getElementById(arg)
   }|}
];

let createOnBody: (int, int) => canvasElement = [%bs.raw
  {|function(width, height) {
    var node = document.createElement('canvas')
    node.width = width
    node.height = height
    document.body.appendChild(node)
    return node
  }|}
];

[@bs.send]
external getContext :
  (canvasElement, [@bs.as "2d"] _) => canvasRenderingContext2D =
  "getContext";

/* canvas api methods */
module Ctx = {
  [@bs.get] external canvas : ctx => canvasElement = "";

  [@bs.send] external drawImage : (ctx, Document.element, int, int) => unit = "";

  [@bs.send] external getImageData : (ctx,  int, int, int, int) => imageData = "";

  let getImageRGBAData: (imageData) => array(int) = [%bs.raw
    {|function(imageData) {
      return imageData.data
    }|}
  ];

  let getColorForCoord: (imageData, int, int, int) => array(int) = [%bs.raw
    {|function(imageData, x, y, width) {
      var data = imageData.data;
      var red = y * (width * 4) + x * 4;
      return [data[red], data[red + 1], data[red + 2], data[red + 3]];
    }|}
  ];

  [@bs.send] external putImageData : (ctx,  imageData, int, int) => unit = "";

  [@bs.set] external setFillStyle : (ctx, string) => unit = "fillStyle";

  [@bs.set] external setStrokeStyle : (ctx, string) => unit = "strokeStyle";

  [@bs.set] external setStrokeWidth : (ctx, float) => unit = "lineWidth";

  [@bs.set] external setLineWidth : (ctx, float) => unit = "lineWidth";

  [@bs.set] external setLineCap : (ctx, string) => unit = "lineCap";

  [@bs.set] external setFont : (ctx, string) => unit = "font";

  [@bs.send] external fillText : (ctx, string, float, float) => unit = "";

  [@bs.send]
  external fillRect : (ctx, float, float, float, float) => unit = "";

  [@bs.send]
  external strokeRect : (ctx, float, float, float, float) => unit = "";

  [@bs.send]
  external clearRect : (ctx, float, float, float, float) => unit = "";

  [@bs.send]
  external ellipse :
    (ctx, float, float, float, float, float, float, float) => unit =
    "";

  let circle = (ctx, x, y, r) =>
    ellipse(ctx, x, y, r, r, 0.0, 0.0, 2.0 *. [%bs.raw "Math.PI"]);

  [@bs.send] external moveTo : (ctx, float, float) => unit = "";

  [@bs.send]
  external arc : (ctx, float, float, float, float, float) => unit = "";

  [@bs.send]
  external arc_rev :
    (ctx, float, float, float, float, float, [@bs.as {json|true|json}] _) =>
    unit =
    "arc";

  let moveToPos = (ctx, (x, y)) => moveTo(ctx, x, y);

  [@bs.send] external lineTo : (ctx, float, float) => unit = "";

  let lineToPos = (ctx, (x, y)) => lineTo(ctx, x, y);

  [@bs.send] external fill : ctx => unit = "";

  [@bs.send] external beginPath : ctx => unit = "";

  [@bs.send] external stroke : ctx => unit = "";

  let line = (ctx, (x, y), (a, b)) => {
    beginPath(ctx);
    moveTo(ctx, x, y);
    lineTo(ctx, a, b);
    stroke(ctx);
  };

  [@bs.send] external save : ctx => unit = "";

  [@bs.send] external restore : ctx => unit = "";

  [@bs.send] external translate : (ctx, int, int) => unit = "";

  [@bs.send] external rotate : (ctx, float) => unit = "";
};

/*
 let createCanvas doc (width: int) (height: int) => {
   let elem = createCanvasElement doc;
   let jscanv = canvasElementToJsObj elem;
   jscanv##width#=width;
   jscanv##height#=height;
   elem
 };
 let createCtx (doc: document) => {
   let canv = createCanvas doc 1000 500;
   addCanvasToBody doc canv;
   getContext canv
 };
 */

let listen_to_canvas: (canvasElement, ((float, float)) => unit) => unit = [%bs.raw
  {|function(canvas, fn) {
    canvas.addEventListener('mousemove', evt => {
      fn([evt.clientX, evt.clientY])
    })
  }|}
];

/*canvas.addEventListener("mousemove", function (e) {
  mousePos = getMousePos(canvas, e);
}, false);

// Get the position of the mouse relative to the canvas
function getMousePos(canvasDom, mouseEvent) {
  var rect = canvasDom.getBoundingClientRect();
  return {
    x: mouseEvent.clientX - rect.left,
    y: mouseEvent.clientY - rect.top
  };
}*/