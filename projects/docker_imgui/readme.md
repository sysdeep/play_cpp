# docker imgui

GUI для docker на базе imGui

## Notes

- при подключении curl бинарник оброс зависимостями по системным либам

## Topics

### Icons

- https://github.com/ocornut/imgui/blob/master/docs/FONTS.md#using-icon-fonts
- https://github.com/xo1337/FontAwesome
- https://github.com/ocornut/imgui/discussions/5275

## CLang

```bash
sudo apt install libstdc++-12-dev
```

## Docker

```bash
# containers
curl localhost:2375/containers/json

# container
curl localhost:2375/containers/28cf1320d2ba4408e389e996ba2dc1e3fab489205dd5d34aba7fe55c3e9b3fba/json

# images
curl localhost:2375/images/json

# image
curl localhost:2375/images/sha256:365268e7ce469d5474b0f544ba2995f9f95f06ae28ede5d02f307f693a36783a/json

# image history
curl localhost:2375/images/sha256:365268e7ce469d5474b0f544ba2995f9f95f06ae28ede5d02f307f693a36783a/history
```
