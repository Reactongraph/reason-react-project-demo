// define stateless component InputField;
let component = ReasonReact.statelessComponent("InputField");

let make = (~value, ~placeholder, ~type_, ~onInputText, _children) => {
  ...component,
  render: _self =>
  <input
    value
    placeholder
    type_
    onChange={event =>
      onInputText(
        ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value,
      )
    }
  />,
};