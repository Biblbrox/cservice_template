![logo](./img/logo-commonalaxy.png)

# Contributing to cservice_template

---

Welcome to `cservice_template`. You're among people eager to promote recommended community standards that encourage contributions with comprehensive [README](../README.md), [CODE_OF_CONDUCT](CODE_OF_CONDUCT.md), [CONTRIBUTING](CONTRIBUTING.md), and [LICENSE](LICENSE.md) documents.

---

## 1. Start

__Contributions__ start with __community conversations__ that lead to __positive change. 

Contributions therefore:

1. Begin with __Issues__,
2. Occur in __Pull Requests__, and
3. End with __Merges__.

---

## 2. __Git__

* ### 2.1. __Rules__

    `cservice_template` manages contributions with the  [feature-branch-workflow](https://www.atlassian.com/git/tutorials/comparing-workflows#feature-branch-workflow).

* #### 2.1.1. Makes changes in a topic branch.

  _Why:_
  > ⌦ Use an isolated topic branch for parallel product development. Topic branches allow you to submit multiple pull requests without confusion. You can iterate without polluting the master branch with potentially unstable, unfinished code.

* #### 2.1.2. Favor the topic branch naming recommendation `type/issue-change-name`.

  _Why:_
  > ⌦ Although not required, our team prefixes branches with the type of change being introduced, followed by a forward slash and the issue id.

Recommended pattern:<br>

- Feature. New feature or enhancement requests.
- Fix. Defect (bug) repair issues.
- Hotfix. Defect (bug) fast repair issues.
- Rebase. Source code design improvements that do not affect product behavior.

Permissible pattern:<br>

  > - Bugfix. Defect (bug) repair issues.
  > - Build. Issues related to product builds.
  > - CI. Issues related to continuous integration, delivery, and deployment tasks.
  > - Docs. Issues related to documentation.
  > - Feat. New feature or enhancement requests.
  > - Perf. Performance improvement issues.
  > - Refactor. Source code design improvements that do not affect product behavior.
  > - Revert. Tasks that revert to a previous commit hash.
  > - Spike. Issues related in solution investigation.
  > - Style. Issues related to style guideline compliance, especially ESLint errors and warnings.
  > - Test. Test coverage tasks.

* #### 2.1.3. Branch out from `master`.

    _Why:_
    > ⌦ `cservice_template` follows the feature-branch-workflow.

* #### 2.1.4. __*Never*__ push into the `master` branch. __*Always*__ submit a Pull Request.

    _Why:_
    > ⌦ It notifies team members whenever changes occur and allows the community to review your changes at any time..
    >
    > It also enables easy peer-review of the code and dedicates forum for discussing the proposed feature.

* #### 2.1.5. Submit a Pull Request as soon as possible.

    _Why:_
    > ⌦ Pull Requests declare work in progress. Frequent pushes to a Pull Request notify your team members about change, and gives them the opportunity to provide feedback more often.
    >
    > Pull Request pushes also trigger automated CI-services, which help you fail fast and assess quality.

* #### 2.1.6. Rebase your local `master` branch before you ask for PR approvals.

    _Why:_
    > ⌦ Rebasing will merge in the requested branch (`master` or `develop`) and apply the commits that you have made locally to the top of the history without creating a merge commit (assuming there were no conflicts). This results in a nice and clean history.

* #### 2.1.7. Resolve rebase conflicts before Pull Request reviews.

    _Why:_
    > ⌦ Rebasing will merge in the `master` branch and apply the commits that you have made locally to the top of it.

* #### 2.1.8. Add reviewers and the label `Status: Needs Review` when the topic branch is ready.

    _Why:_
    > ⌦ When you add a Reviewer, GitHub (or Bitbucket) notifies teammates that your topic branch meets all Acceptance Criteria and is ready to be merged into `master`.
    >
    > Add the label "Status: Review Needed" formally declares the status of your topic branch, and helps teams filter through issues.

* #### 2.1.9. Delete local and remote topic branches after merging.

    _Why:_
    > ⌦ Topic branches should only exist while work is in-progress. Merged topic branches clutter up your list of branches with dead branches. Topic branch deletion also insures that you only ever merge back into `master`.

* ### 2.2. __Feature-branch-workflow__

  We use the  [feature-branch-workflow](https://www.atlassian.com/git/tutorials/comparing-workflows#feature-branch-workflow). We _recommend_ [interactive rebasing](https://www.atlassian.com/git/tutorials/merging-vs-rebasing#the-golden-rule-of-rebasing), too, but that's not required.



* #### 2.2.1. Initialize a Git repository in the product directory (_for new repositories only_).

  For subsequent features and changes, this step should be ignored.

  ```
  cd cservice_template && git init
  ```

* #### 2.2.2. Checkout a new `feat`ure or `fix` branch.

  For a new feature branch:

  ```git checkout -b feat/<issueId>-scope-of-change```

  For branches that address defects:

  ```git checkout -b fix/<issueId>-scope-of-change```

* #### 2.2.3. Make Changes.

  ```
  git add . &&
  git commit -m "Pattern. Changelist."
  ```

  _Why:_
  > ⌦ `git commit -a` will start an editor which lets you separate the subject from the body.

* #### 2.2.4. Follow the Conventional Commits Specification for commit messages.

  * __`build` commit messages__

    Issues related to product builds.

    ```
    build(<scope>): <subject>
    <BLANK LINE>
    <[body]>
    <BLANK LINE>
    <footer>
    ```

  * __`chore` commit messages__

    Issues related to miscellaneous non-functional changes (usually "maintenance" changes).

    ```
    chore(<scope>): <subject>
    <BLANK LINE>
    <[body]>
    <BLANK LINE>
    <footer>
    ```

  * __`ci` commit messages__

    Issues related to continuous integration, delivery, and deployment tasks.

    ```
    ci(<scope>): <subject>
    <BLANK LINE>
    <[body]>
    <BLANK LINE>
    <footer>
    ```

  * __`docs` commit messages__

    Issues related to documentation.

    ```
    docs(<scope>): <subject>
    <BLANK LINE>
    <[body]>
    <BLANK LINE>
    <footer>
    ```

  * __`feat` (feature) commit messages__

    New feature or enhancement requests.

    ```
    feat(<scope>): <subject>
    <BLANK LINE>
    <[body]>
    <BLANK LINE>
    <footer>
    ```

  * __`fix` commit messages__

    Defect (bug) repair issues.

    ```
    fix(<scope>): <subject>
    <BLANK LINE>
    <[body]>
    <BLANK LINE>
    <footer>
    ```

  * __`perf` (performance) commit messages__

    Performance improvement issues.

    ```
    perf(<scope>): <subject>
    <BLANK LINE>
    <[body]>
    <BLANK LINE>
    <footer>
    ```

  * __`refactor` commit messages__

    Source code design **improvements that do not affect product behavior**.

    ```
    refactor(<scope>): <subject>
    <BLANK LINE>
    <[body]>
    <BLANK LINE>
    <footer>
    ```

  * __`revert` commit messages__

    Tasks that revert to a previous commit hash. Your message should begin with `revert:`, followed by the header of the reverted commit.

    In the body it should say: `This reverts commit <hash>.`, where the hash is the SHA of the commit being reverted.

    ```
    revert: <hash>
    <BLANK LINE>
    This reverts commit <hash>.
    <BLANK LINE>
    <footer>
    ```

  * __`style` commit messages__

    Issues related to style guideline compliance, especially `ESLint` errors and warnings.

    ```
    style(<scope>): <subject>
    <BLANK LINE>
    <[body]>
    <BLANK LINE>
    <footer>
    ```

  * __`test` commit messages__

    Test coverage tasks.

    ```
    test(<scope>): <subject>
    <BLANK LINE>
    <[body]>
    <BLANK LINE>
    <footer>
    ```

* #### 2.2.5. Sync with remote to get changes you’ve missed.

  ```
  git checkout master
  git pull
  ```

  _Why:_
  > ⌦ This will give you a chance to deal with conflicts on your machine while rebasing(later) rather than creating a Pull Request that contains conflicts.

* #### 2.2.6. Update your topic branch with the latest changes from `master` by interactive rebase.

  ```
  git checkout <branchname>
  git rebase -i --autosquash master
  ```

  _Why:_
  > ⌦ You can use `--autosquash` to squash all your commits to a single commit. Nobody wants many commits for a single feature in develop branch.
  >
  > [Learn more about autosquashing Git commits][autosquashing-git-commits-url].

* #### 2.2.7. Resolve conflicts (if any occur), and continue rebase.

  ```
  git add <file1> <file2> ...
  git rebase --continue
  ```

  [Learn more about resolving conflicts][git-resolve-conflicts-url].

* #### 2.2.8. Push your branch with the `-f` flag (if necessary).

  Rebase changes history, so you might need to force changes into the `remote` branch with the `-f` flag. If someone else is working on your branch, use the less destructive `--force-with-lease`.

  ```
  git push -f
  ```

  _Why:_
  > ⌦ When you do a rebase, you are changing the history on your topic branch. As a result, Git will reject normal `git push`. Instead, you'll need to use the -f or --force flag.
  >
  > [Learn more about `--force-with-lease`][force-with-lease-url].

* #### 2.2.9. Submit a Pull Request.

* #### 2.2.10. Once accepted, the Pull request will be merged, closed, and deleted by an administrator.

* #### 2.2.11. Remove your local topic branch if you're done.

  ```
  git branch -d <branchname>
  ```

  to remove all branches which are no longer on remote

  ```
  git fetch -p && \
    for branch in `git branch -vv | grep ': gone]' | awk '{print $1}'`; \
      do git branch -D $branch; \
    done
  ```
---

## 3. __Unit testing__

* ### 3.1. Write GTests tests.

  _Why:_
  > ⌦ Behavior-driven development specifications are executable documentation.

  * **Put test files in the *tests/* directory.**

* ### 3.2. Reach 100% code coverage.

  _Why:_
  > ⌦ Full coverage makes automated dependency drift updates safer.

  * View a test coverage summary in the Terminal:

      PASS  __tests__/class.cpp
       generator-community:app
        ✓ creates files (1ms)

    Test Suites: 1 passed, 1 total
    Tests:       1 passed, 1 total
    Snapshots:   0 total
    Time:        2.595s
    Ran all test suites.

  * Open `doc/coverage/lcov-report/index.html` in a Web browser to view detailed coverage reports.

---
