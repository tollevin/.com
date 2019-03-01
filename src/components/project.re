let component = ReasonReact.statelessComponent("Project");

let make = (~image, ~company, ~role, ~description, ~achievements, ~website, ~location, ~startDate, ~endDate, ~highlights, _children) => {
	...component,
	render: (_self) =>
		<div className="project">
			<img src=image alt=company />
			<div className="project-header">
				<div className="header-group">
					<div className="header-group">
						<span className="company">(ReasonReact.string(company))</span>
						<span className="location">(ReasonReact.string(location))</span>
					</div>
					<span className="website">(ReasonReact.string(website))</span>
				</div>
				<div className="header-group role-span">
					<span className="role">(ReasonReact.string(role))</span>
					<span className="timespan">(ReasonReact.string(startDate))(ReasonReact.string(" - "))(ReasonReact.string(endDate))</span>
				</div>
			</div>
			<div className="description">(ReasonReact.string(description))</div>
			<div className="achievements">
				<ul>
					(
						ReasonReact.array(
							Array.of_list(
								List.map((achievement) => <li>(ReasonReact.string(achievement))</li>, achievements)
							)
						)
					)
				</ul>
			</div>
			<div className="highlights">
				<ul>
					(
						ReasonReact.array(
							Array.of_list(
								List.map((highlight) => <li>(ReasonReact.string(highlight))</li>, highlights)
							)
						)
					)
	      </ul>
	    </div>
		</div>,
}