type p5;

type p5Inst = {
	mutable preload: unit => unit,
	mutable setup: unit => unit,
	mutable draw: unit => unit,
	mutable redrawHandler: unit => unit,	
};

type p;

type p5Image = {
	width: int,
	height: int,
	pixels: list(int)
};

type p5Renderer = {
	elt: string,
	pInst: p5,
	isMainCanvas: bool
};

type gray = int;

type p5Color = list(int);

type canvas;

type a;

[@bs.new][@bs.module ("../js/p5.js","p5")] external p5 : unit => p = "p5";
[@bs.module ("../js/p5.js","p5")] external loadImage : (string) => p5Image = "";
[@bs.send] external loadPixels : p5Image => unit = "";
[@bs.send] external get : p5Image => (int, int) => a = "";
[@bs.send] external createCanvas : (int, int) => p5Renderer = "";
/*[@bs.val][@bs.module ("../js/p5.js","p5")] external print : (string) => unit = "";*/
/*[@bs.val][@bs.module ("../js/p5.js","p5")] external width : string => unit = "";*/
[@bs.send] external background : (gray) => unit = "";
[@bs.val][@bs.module ("../js/p5.js","p5")] external map : (int, int, int, float, float) => float = "";
[@bs.val][@bs.module ("../js/p5.js","p5")] external color : (a) => p5Color = "";
[@bs.val] external round : float => int = "Math.round";
[@bs.val][@bs.module ("../js/p5.js","p5")] external red : p5Color => int = "";
[@bs.val][@bs.module ("../js/p5.js","p5")] external green : p5Color => int = "";
[@bs.val][@bs.module ("../js/p5.js","p5")] external blue : p5Color => int = "";
[@bs.send] external stroke : int => unit = "";
[@bs.send] external strokeWithP5Color : p5Color => unit = "";
[@bs.send] external strokeWithRGB : (int, int, int) => unit = "";
[@bs.send] external strokeWithTuple : (int, int) => unit = "";
[@bs.send] external strokeWeight : int => unit = "";
[@bs.send] external line : (int, int, int, int) => unit = "";
[@bs.send] external fillWithP5Color : p5Color => unit = "fill";
[@bs.send] external fillWithTuple : (int, int) => unit = "fill";
[@bs.send] external fillWithTriple : (int, int, int) => unit = "fill";
[@bs.send] external fill : int => unit = "";
[@bs.send] external noFill : unit => unit = "";
[@bs.send] external noStroke : unit => unit = "";
[@bs.val] external sqrt : float => float = "Math.sqrt";
[@bs.send] external ellipse : (int, int, int, int) => unit = "";
[@bs.send] external push : unit => unit = "";
[@bs.send] external translate : (int, int) => unit = "";
[@bs.send] external rotate : float => unit = "";
[@bs.send] external pop : unit => unit = "";
[@bs.val][@bs.module ("../js/p5.js","p5")] external min : (int, int) => int = "";
[@bs.val][@bs.module ("../js/p5.js","p5")] external floor : float => int = "";
[@bs.send] external rect : (int, int, float, float) => unit = "";