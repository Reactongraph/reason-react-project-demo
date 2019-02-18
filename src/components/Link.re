let component = ReasonReact.statelessComponent("Link");
let make = (~route, ~toUrl, ~render, _children) => {
  ...component,
  render: _self => {
    let href = toUrl(route);
    let onClick = e => {
      ReactEventRe.Mouse.preventDefault(e);
      ReasonReact.Router.push(href);
    };
    <a href onClick className="menuItem"> {render()} </a>;
  },
};