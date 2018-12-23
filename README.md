 list-kingdom
A tiny command-line list maker

### Basic functionality:
- [x] Users can add items to a list
- [ ] Users can remove items from a list
- [ ] Users can marks items on a list as "complete" or "incomplete"
- [x] Items are saved to a file
- [x] Users can read items from a list
- [ ] Users can edit items

- [ ] Users can create categories for items (such as "to do today" or "Work" or "Crafts")
- [ ] Users can create subtasks on tasks
- [ ] Subtasks (or steps to completing a task) can be viewed as a tree of complete and incomplete tasks
- [ ] Tasks with subtasks can be folded up (so that subtasks are invisible) or opened
- [ ] Categories can be folded up or opened

An example of an unfolded tree:
```[ ] my first task -
               |\_ [ ]this is the first subtask
               |\_ [x]this is the second subtask
               |
               |\_ [x]this is the third subtask
               |              \_ [x]task one
               |              \_ [x]task two
               |              \_ [x]task three
               |
               |\_ [ ]this is the fourth subtask
                \_ [x]this is the last task! ```

An example of a folded tree:
```[ ] my first task [...]```

### how to run it:
If you are on unix, clone down this directory from within the command line. 
`cd` into the cloned directory.
Run `gcc -std=c11 task.c -o task` (or whatever build command you prefer!) and then, in the same directory, enter `./task`.
