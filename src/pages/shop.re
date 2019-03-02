let component = ReasonReact.statelessComponent("Shop");

let make = (_children) => {
	...component,
	render: self => 
		<div id="Shop" className="page">
			<h1 className="page-title">(ReasonReact.string("shop"))</h1>
			<h2 className="coming-soon">(ReasonReact.string("coming soon"))</h2>
		</div>,
}