```
 __                           __               __
/\ \__                       /\ \             /\ \__
\ \ ,_\   ___   __  __    ___\ \ \___     ____\ \ ,_\   ___     ___      __
 \ \ \/  / __`\/\ \/\ \  /'___\ \  _ `\  /',__\\ \ \/  / __`\ /' _ `\  /'__`\
  \ \ \_/\ \L\ \ \ \_\ \/\ \__/\ \ \ \ \/\__, `\\ \ \_/\ \L\ \/\ \/\ \/\  __/
   \ \__\ \____/\ \____/\ \____\\ \_\ \_\/\____/ \ \__\ \____/\ \_\ \_\ \____\
    \/__/\/___/  \/___/  \/____/ \/_/\/_/\/___/   \/__/\/___/  \/_/\/_/\/____/
```

this is a simple C test framework written from scratch

### current features:

- check if a value is non-zero
- check if two values are numerically equal

### usage:

- include `touchstone.h`
- write tests using `ts_assert()` or `ts_assert_eq()`
- compile your tests with `-ltouchstone`

### screenshot:

![Screenshot of touchstone in use](screenshot.png?raw=true "Screenshot")
