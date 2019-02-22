// defines states
type state = {
  items: list(TodoType.item),
  inputText: string,
};

// defines actions
type action =
  | InputText(string)
  | Toggle(int)
  | RemoveItem(int)
  | Submit;

// defines Statefull component names Todo
let component = ReasonReact.reducerComponent("TodoTask");

let make = _children => {

  // Added new item in list
  let handleSubmit = state => {
    // ReasonReact.Router.push("Home");
    let newId: int = List.length(state.items);
    let newItem: TodoType.item = {
      id: newId,
      title: state.inputText,
      completed: false,
    };
    let newList = [newItem, ...state.items];
    ReasonReact.Update({items: newList, inputText: ""});
  };

  let handleLogout =() => {
    ReasonReact.Router.push("/");
  };

  // defines initial state
  {
    ...component,
    initialState: () => {
      items: [
        {id: 0, title: "First Item added in toDo list", completed: false},
      ],
      inputText: "",
    },

    reducer: action =>
      switch (action) {
      // update state of input field
      | InputText(newText) => (
          state => ReasonReact.Update({...state, inputText: newText})
        )

      // added item completed or not
      | Toggle(id) => (
          state =>
            ReasonReact.Update({
              ...state,
              items:
                List.map(
                  (item: TodoType.item) =>
                    item.id == id ?
                      {
                        ...item,
                        TodoType.completed: !TodoType.(item.completed),
                      } :
                      item,
                  state.items,
                ),
            })
        )

      // Remove item for list
      | RemoveItem(id) => (
          state =>
            ReasonReact.Update({
              ...state,
              items:
                List.filter(
                  (item: TodoType.item) => item.id !== id,
                  state.items,
                ),
            })
        )
      // Submit an items
      | Submit => (state => handleSubmit(state))
      },

    render: self => {
      let {items, inputText} = self.state;
        <div className="container">
          <div className="logout-button">
            <button onClick={ _=> handleLogout()} className="button">{ReasonReact.string("Logout")} </button>
          </div>
          <div className="input-div">
            <Input
              submit={_ => self.send(Submit)}
              value=inputText
              onInputText={text => self.send(InputText(text))}
            />
          </div>
          <div className="list-div">
            <div className="list">
                {ReasonReact.array(
                  Array.of_list(
                    List.map(
                      (item: TodoType.item) =>
                        <Item
                          key={string_of_int(item.id)}
                          item
                          onRemove={id => self.send(RemoveItem(id))}
                          onToggle={id => self.send(Toggle(id))}
                        />,
                      items,
                    ),
                  ),
                )}
              </div>
          </div>
        </div>
    },
  };
};