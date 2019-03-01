let component = ReasonReact.statelessComponent("PostPreview");

let make = (~enclosure, ~title, ~description, ~pubDate, _children) => {
  ...component,
  render: (_self) =>
    <div className="post-preview">
    	<img src=enclosure alt=title />
      <h3>(ReasonReact.string(title))</h3>
      <p className="teaser">(ReasonReact.string(description))</p>
      <span className="pub-date">(ReasonReact.string(pubDate))</span>
    </div>
};