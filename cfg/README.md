# Configuration file

---

**[main]**<br/>

| Parameter | Description                                 | Type | Default |
| :-------- | :------------------------------------------ | :--: | :-----: |
| debug     | Flag if need trace service info to log file | bool | *false* |

<br/>

---

**[receive]**<br/>

| Parameter | Description                                | Type   | Default |
| :-------- | :----------------------------------------- | :----  | :-----: |
| target    | Inter Process Communications               | string | *ipc*   |
| prefix    | ZCM in channel prefix                      | string |         |
| channel   | ZCM out channel prefix                     | string |         |

<br/>

---

**[send]**<br/>

| Parameter | Description                                | Type   | Default |
| :-------- | :----------------------------------------- | :----  | :-----: |
| target    | Inter Process Communications               | string | *ipc*   |
| prefix    | ZCM in channel prefix                      | string |         |
| channel   | ZCM out channel prefix                     | string |         |

<br/>

---

**[logs]**<br/>

| Parameter    | Description                                              | Type   | Default           |
| :----------- | :------------------------------------------------------- | :----  | :---------------: |
| need_trace   | Flag if need log service messages to file                | bool   | true              |
| need_shared  | Flag if need write all logging levels to one file        | bool   | true              |
| shared_name  | Shared log filename                                      | string | *$$FULL_APP.log*  |
| need_leveled | Flag if need write each level of logging to its own file | bool   | true              |
| leveled_path | Leveled logs path                                        | string | *$$APP_PATH/logs* |
| file_sizes   | Log max size in Kb                                       | uint   | 1e6               |
| rotates      | Max logs count                                           | uint   | 3                 |

<br/>

---
