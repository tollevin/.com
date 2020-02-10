type element;

type document;

type window;

type keyboardEvent;

type mouseEvent;

type image;

[@bs.val] external document : document = "Document";

[@bs.val] external getWindowWidth : int = "window.innerWidth";
[@bs.val] external getWindowHeight : int = "window.innerHeight";

[@bs.new] external image : unit => element = "Image";

[@bs.set] external setImgSrc : (element, string) => unit = "src";

/*[@bs.set] external onLoad : (element, unit) => unit = "onload";*/
[@bs.set] external set_onload: (element, [@bs.this] ((element, int) => unit)) => unit = "onload";

[@bs.get] external naturalHeight : element => int = "";

[@bs.get] external naturalWidth : element => int = "";

[@bs.val]
external createElement : string => element = "document.createElement";

[@bs.val]
external appendChild : element => element = "document.body.appendChild";

[@bs.send] external addEventListener : (element, string, mouseEvent => unit) => unit = "addEventListener";

[@bs.send] external removeEventListener : (element, string, unit => unit) => unit = "removeEventListener";

[@bs.get] external getClientX : mouseEvent => int = "clientX";

[@bs.get] external getClientY : mouseEvent => int = "clientY";

[@bs.get] external getWidth : element => int = "innerWidth";

[@bs.get] external getHeight : element => int = "innerHeight";

[@bs.set] external setWidth : (element, int) => unit = "width";

[@bs.set] external setHeight : (element, int) => unit = "height";

[@bs.return null_to_opt] [@bs.send]
external getElementById : (document, string) => option(element) = "";

external keyboardEventToJsObj : keyboardEvent => Js.t({..}) = "%identity";

let listen_for_mouseEvt: (((float, float)) => unit) => unit = [%bs.raw
  {|function(fn) {
    window.addEventListener('mousemove', evt => {
      fn([evt.clientX, evt.clientY])
    })
  }|}
];

let listen_for_touchEvt: (((float, float)) => unit) => unit = [%bs.raw
  {|function(fn) {
    window.addEventListener('touchmove', evt => {
      fn([evt.touches[0].clientX, evt.touches[0].clientY])
    })
  }|}
];