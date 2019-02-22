// define stateless component Button
let component = ReasonReact.statelessComponent("Button");

let make = (~onClick, ~buttonText, _children) => {
  ...component,
  render: _self =>
    <button onClick={onClick}> {buttonText} </button>
};