# MyINFO OS

OS from scratch using Nick Blundell, Bran's Kernel and OSDev.org.


### Build

```sh
make
```

To clean
```sh
make clean
```

### Use

With a usb device
```sh
sudo dd if=os.img of=/dev/sdX
```

With qemu 
```sh
qemu-system-x86_64 os.img
```


