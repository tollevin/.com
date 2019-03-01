let component = ReasonReact.statelessComponent("Link");

let make = (~href, ~onClick, children) => {
	let click = (event) => {
		if (! ReactEvent.Mouse.defaultPrevented(event)) {
	    ReactEvent.Mouse.preventDefault(event);
	  };
	  ReasonReact.Router.push(href);
	  onClick(event);
  };
  {
	  ...component,
	  render: (_self) => ReasonReact.createDomElement("a", ~props={"href": href, "onClick": click}, children),
	}
};