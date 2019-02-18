// import App.css
[%bs.raw {|require('../App.css')|}];
// import logo.svg
[@bs.module] external logo: string = "../logo.svg";

// define stateless component
let component = ReasonReact.statelessComponent("Home");

//  ReasonReact.string(). is used to render string
let make = (~message, _children) => {
  ...component,
  render: _self =>
    <div className="App">
      <div className="App-header">
        <img src=logo className="App-logo" alt="logo" />
        <h2> {ReasonReact.string(message)} </h2>
      </div>
    </div>,
};