let str = ReasonReact.string;
// define stateless component named Input
let component = ReasonReact.statelessComponent("Input");

let make = (~value, ~onInputText, ~submit, _children) => {
  ...component,
  render: _self =>
    <div className="input">
      <input
        value
        placeholder="Enter item"
        onChange=(
          event =>
            onInputText(
              ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value,
            )
        )
      />
      <button onClick=(_ => submit())> (str("Add")) </button>
    </div>,
};