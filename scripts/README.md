# Scripts

Scripts for app manipulating.

---

- [update_submodules.sh](update_submodules.sh)

    Allow to update dependent submodules. After updating build them.

---

- [install.sh](install.sh)

    Installs all basic dependencies for the basic functioning of the application without visualization or documentation.

---

- [install-third-party.sh](install-third-party.sh)

    Installs all basic dependencies for the all functioning of the application with data and code-coverage visualization, documentation.

---

- [build.sh](build.sh)

    Builds the application without visualization together with updated submodules. The output is a binary file in the *build* subdirectory.

---

- [build-gui.sh](build-gui.sh)

    Builds the application without visualization together with updated submodules. The output is a binary file in the *build* subdirectory.

---

- [sanalyze.sh](sanalyze.sh)

    Performs static analysis of the project code using CLang-Tidy.

---

- [test.sh](test.sh)

    Starts unit testing of the service code.

---

- [doc.sh](doc.sh)

    Carries out auto-documenting of code according to Doxygen tags. For visualization, you can use any browser by first opening: <br/>

```your-browser ./doc/doxygen/html/index.html```

---

- [run.sh](run.sh)

    Launch the application taking into account the [arguments](http://bb.niias/projects/TOOL/repos/niias_srv_supply/browse):<br/>

| Argument| Description                | Example                      |
|---------|----------------------------|------------------------------|
| -c      | Path to configuration file | ../cfg/cservice_template.cfg |
| -p      | Path to application PID    | /tmp/cservice_template       |
| others  | -                          | -                            |

---

- [refresh.sh](refresh.sh)

    Clears all temporary IDE files.

---

- [rename.sh](rename.sh)

    Renames all lines with cservice_template in the whole project to the new project naming according to the script input argument.

*Example:* <br>

```./scripts/rename.sh cservice_template cservice_template cservice_template preview``` - preview change files and lines.

```./scripts/rename.sh cservice_template cservice_template cservice_template``` - recursively replace first argument to second in all files.

---