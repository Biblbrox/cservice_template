# Scripts

Scripts for app manipulating.

---

- update_submodules.sh

    Allow to update dependent submodules. After updating build them.

---

- build.sh

    Builds the application together with updated submodules. The output is a binary file in the *build* subdirectory.

---

- test.sh

    Starts unit testing of the service code.

---

- doc.sh

    Carries out auto-documenting of code according to Doxygen tags. For visualization, you can use any browser by first opening: <br/>

```your-browser ./doc/doxygen/html/index.html```

---

- run.sh

    Launch the application taking into account the arguments:<br/>

| Argument| Description                | Example                      |
|---------|----------------------------|------------------------------|
| -c      | Path to configuration file | ../cfg/cservice_template.cfg |
| -p      | Path to application PID    | /tmp/cservice_template       |


---

- refresh.sh

    Clears all temporary IDE files.

---