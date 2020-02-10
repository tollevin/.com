let component = ReasonReact.statelessComponent("PostPreview");

let make = (~enclosure, ~title, ~description, ~content, ~pubDate, _children) => {
  ...component,
  render: (_self) =>
    <div className="post-preview" key=title>
    	<img src=enclosure alt=title />
    	<div className="post-text">
	      <h3>(ReasonReact.string(title))</h3>
	      <span className="pub-date">(ReasonReact.string(pubDate))</span>
	      <p className="teaser">(ReasonReact.string(description))</p>
	    </div>
    </div>
};