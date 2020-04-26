!!! NEVER EVER INSTALL [XF86-VIDEO-INTEL](https://www.archlinux.org/packages/extra/x86_64/xf86-video-intel/) !!!
[<sup>O</sup>](https://www.reddit.com/r/archlinux/comments/6am55w/is_xf86videointel_still_needed/)
[<sup>O</sup>](https://askubuntu.com/questions/1200289/performance-issues-modesetting-vs-xf86-video-intel)
[<sup>O</sup>](https://forum.peppermintos.com/index.php?topic=7957.0)
[<sup>O</sup>](https://www.linuxquestions.org/questions/slackware-14/intel-recommended-x-driver-4175647103/)
<!--
[<sup>O</sup>]()
-->

See also [wayland](https://github.com/Un1Gfn/wayland)

---

###### Force 1080P

* https://askubuntu.com/a/776502

```
cvt 1920 1080 60
# 1920x1080 59.96 Hz (CVT 2.07M9) hsync: 67.16 kHz; pclk: 173.00 MHz
Modeline "1920x1080_60.00"  173.00  1920 2048 2248 2576  1080 1083 1088 1120 -hsync +vsync

xrandr --newmode "1920x1080_60.00"  173.00  1920 2048 2248 2576  1080 1083 1088 1120 -hsync +vsync
xrandr --verbose --addmode VGA-1 "1920x1080_60.00"
xrandr --output VGA-1 --mode "1920x1080_60.00"
xrandr --output VGA-1 --mode 640x480
xrandr --output VGA-1 --mode 1024x768
xrandr --output VGA-1 --auto
```

```bash
function f {
  item="$(cvt $1 $2 $3 | tail -1 | cut -b 10-)"
  title="$(echo "$item" | cut -d ' ' -f 1)"
  echo "$item"
  echo "$title"
  xrandr --newmode $item
  xrandr --verbose --addmode VGA-1 "$title"
  xrandr --output VGA-1 --mode "$title"
}
f 1920 1080 60
f 1920 1200 60
f 1400 1050 60
# f 1366 768 60
```

```bash
# xrandr --verbose --output LVDS-1 --off
xrandr --verbose --output VGA-1 --mode 1024x768
xrandr --verbose --delmode VGA-1 new_mode
xrandr --verbose --rmmode new_mode

# xrandr --verbose --newmode new_mode $(cvt 1920 1080 60 | tail -1 | cut -d' ' -f3-)
xrandr --verbose --newmode new_mode $(cvt 1600 900 60 | tail -1 | cut -d' ' -f3-)
xrandr --verbose --addmode VGA-1 new_mode
xrandr --verbose --output VGA-1 --mode new_mode
sleep 13
xrandr --verbose --output VGA-1 --mode 1024x768

xrandr --verbose --output VGA-1 --transform 1,0,0,0,1,0,0,0,1

xrandr --verbose --output VGA-1 --transform 1,0,0,0,1,0,0,0,1
xrandr --verbose --output VGA-1 --transform 1,0,0,0,2,0,0,0,1

xrandr --verbose --output VGA-1 --transform 1,0,0,0,1,0,0,0,1
xrandr --verbose --output VGA-1 --transform 1,0,50,0,1,50,0,0,1
```

```bash
xrandr --transform 
```


###### kms+xorg+picom+i3

* [Kernel Mode Setting](https://www.kernel.org/doc/html/latest/gpu/drm-kms.html)
  * [Archwiki](https://wiki.archlinux.org/index.php/Kernel_mode_setting)
  * [Wikipedia](https://en.wikipedia.org/wiki/Mode_setting)
* [X.Org](https://www.x.org/wiki/)
  * [Xlib](https://en.wikipedia.org/wiki/Xlib) [<sup>libx11</sup>](https://www.archlinux.org/packages/extra/x86_64/libx11/)
  * [XCB](https://en.wikipedia.org/wiki/XCB) [<sup>libxcb</sup>](https://www.archlinux.org/packages/extra/x86_64/libxcb/)
  * []() [<sup>xorg-server</sup>](https://www.archlinux.org/packages/extra/x86_64/xorg-server/)
* [picom](https://github.com/yshui/picom)
  * [Archwiki](https://wiki.archlinux.org/index.php/Picom)
* [i3](https://i3wm.org/)
  * [GitHub](https://github.com/i3/i3)

###### Terminal

* Color schemes
  * [terminal.sexy](https://terminal.sexy/)

* [rxvt-unicode](http://software.schmorp.de/pkg/rxvt-unicode.html)
  * [Archwiki](https://wiki.archlinux.org/index.php/Rxvt-unicode)
  * [cvs](http://cvs.schmorp.de/rxvt-unicode/)
  * [quickstart](https://addy-dclxvi.github.io/post/configuring-urxvt/)
  * [X resources](https://wiki.archlinux.org/index.php/X_resources)
  * [Reddit](https://www.reddit.com/r/urxvt)
  * [urxvt-perls](https://github.com/muennich/urxvt-perls)

Mod1+Enter ~ Mod1+h ~ Mod1+Enter ~ ... ~ Mod1+Enter ~ Mod1+W

* [Neovim](https://neovim.io/)
  * [wiki](https://github.com/neovim/neovim/wiki)
  * [Archwiki](https://wiki.archlinux.org/index.php/Neovim)
  * [monokai by crusoexia](https://github.com/crusoexia/vim-monokai)
  <!-- * [sickill](https://github.com/sickill/vim-monokai) too much red -->
  <!-- * [patstockwell](https://github.com/patstockwell/vim-monokai-tasty) parse error -->




###### /home/darren/.config/gtk-3.0/gtk.css

[Blog](https://blog.gtk.org/2017/04/05/the-gtk-inspector/)

```bash
$ file /home/darren/.config/dconf/user
/home/darren/.config/dconf/user: GVariant Database file, version 0

$ gsettings set org.gtk.Settings.Debug enable-inspector-keybinding true
$ md5sum /home/darren/.config/dconf/user
4515114421d9442fad1b9d0171497cbf  /home/darren/.config/dconf/user

$ gsettings set org.gtk.Settings.Debug enable-inspector-keybinding false
$ md5sum /home/darren/.config/dconf/user
276fecf147f145176dc1b53614a8154c  /home/darren/.config/dconf/user

$ gsettings set org.gtk.Settings.Debug enable-inspector-keybinding true
$ md5sum /home/darren/.config/dconf/user
4515114421d9442fad1b9d0171497cbf  /home/darren/.config/dconf/user
```

Gnome-terminal ~ Help ~ Inspector

###### GTK3

/home/darren/.config/gtk-3.0
/home/darren/.config/gtk-3.0/bookmarks
```
file:///home/darren/db/exp01
file:///tmp tmp
[...]
```

###### GTK2

/home/darren/.gtkrc-2.0.bak
/home/darren/.gtkrc.tmp-0

./.gtkrc-2.0


```
$ inxi -G
Graphics:  Device-1: Intel Mobile 4 Series Integrated Graphics driver: i915 v: kernel 
           Display: server: X.org 1.20.8 driver: i915 resolution: <xdpyinfo missing> 
           OpenGL: renderer: Mesa DRI Mobile Intel GM45 Express (CTG) v: 2.1 Mesa 20.0.4 

# lspci -k -nn -d 8086:2a43
00:02.1 Display controller [0380]: Intel Corporation Mobile 4 Series Chipset Integrated Graphics Controller [8086:2a43] (rev 07)
  Subsystem: Lenovo Mobile 4 Series Chipset Integrated Graphics Controller [17aa:20e4]

# lspci -k -nn -d 8086:2a42
00:02.0 VGA compatible controller [0300]: Intel Corporation Mobile 4 Series Chipset Integrated Graphics Controller [8086:2a42] (rev 07)
  Subsystem: Lenovo Mobile 4 Series Chipset Integrated Graphics Controller [17aa:20e4]
  Kernel driver in use: i915
  Kernel modules: i915
```





cp /etc/X11/xorg.conf.d/20-intel.conf.old _etc_X11_xorg.conf.d_20-intel.conf
