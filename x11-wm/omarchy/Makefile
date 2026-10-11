PORTNAME=	omarchy
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.4
CATEGORIES=	x11-wm

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	Beautiful, modern, and opinionated Hyprland desktop by DHH
WWW=		https://omarchy.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# freebsdize, which adapts the sources, is a bash script run while patching.
PATCH_DEPENDS=	bash:shells/bash
BUILD_DEPENDS=	magick:graphics/ImageMagick7
RUN_DEPENDS=	Hyprland:x11-wm/hyprland \
		basuctl:devel/basu \
		ck-launch-session:sysutils/consolekit2 \
		dbus-run-session:devel/dbus \
		flock:sysutils/flock \
		gawk:lang/gawk \
		gfind:misc/findutils \
		ggrep:textproc/gnugrep \
		git:devel/git \
		gnome-keyring-daemon:security/gnome-keyring \
		gsed:textproc/gsed \
		gnustat:sysutils/coreutils \
		gtk-launch:x11-toolkits/gtk30 \
		gum:devel/gum \
		inotifywait:sysutils/inotify-tools \
		jq:textproc/jq \
		mise:sysutils/mise \
		pipewire:multimedia/pipewire \
		quickshell:x11/quickshell \
		seatd:sysutils/seatd \
		setsid:sysutils/setsid \
		upower:sysutils/upower \
		wireplumber:multimedia/wireplumber \
		xdg-mime:devel/xdg-utils \
		xdg-terminal-exec:deskutils/xdg-terminal-exec \
		xdg-user-dirs-update:devel/xdg-user-dirs \
		${LOCALBASE}/bin/getopt:misc/getopt \
		${LOCALBASE}/libexec/xdg-desktop-portal-hyprland:x11/xdg-desktop-portal-hyprland \
		${LOCALBASE}/share/fonts/nerd-fonts/JetBrainsMono/JetBrainsMonoNerdFont-Regular.ttf:x11-fonts/nerd-fonts-jetbrainsmono

USES=		fonts perl5 python:run shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	basecamp
# The FreeBSD compatibility layer: freebsdize, compat tools, FreeBSD commands.
GH_TUPLE=	jordanhubbard:omarchy-freebsd:v1.0.0:freebsd
USE_PERL5=	run

SHEBANG_FILES=	bin/* config/omarchy/hooks/*/* default/systemd/system-sleep/* \
		install/user/first-run/* shell/plugins/*/*.sh shell/services/*.sh

FONTNAME=	omarchy
SUB_FILES=	pkg-message
SUB_LIST=	DATADIR=${DATADIR} PREFIX=${PREFIX}

# GNU userland that Omarchy's scripts are written against, linked under their
# plain names into a private directory on the scripts' PATH.
GNU_COREUTILS=	b2sum base32 base64 basename basenc cat chgrp chmod chown \
		chroot cksum comm cp csplit cut date dd df dir dircolors dirname \
		du echo env expand expr factor false fmt fold groups head hostid \
		id install join kill link ln logname ls md5sum mkdir mkfifo mknod \
		mktemp mv nice nl nohup nproc numfmt od paste pathchk pinky pr \
		printenv printf ptx pwd readlink realpath rm rmdir seq sha1sum \
		sha224sum sha256sum sha384sum sha512sum shred shuf sleep sort \
		split stdbuf stty sum sync tac tail tee test timeout touch tr \
		true truncate tsort tty uname unexpand uniq unlink uptime users \
		vdir wc who whoami yes
GNU_OTHER=	stat:gnustat awk:gawk egrep:gegrep fgrep:gfgrep find:gfind getopt:getopt \
		grep:ggrep sed:gsed xargs:gxargs

COMPAT_TOOLS=	brightnessctl journalctl powerprofilesctl setpriv systemctl \
		systemd-cat systemd-inhibit systemd-run timedatectl uwsm uwsm-app

# Directories copied into ${DATADIR} as-is (after the FreeBSD adjustments).
DATA_DIRS=	applications config default install migrations shell themes

# Paths the Arch package uses that live under ${PREFIX} on FreeBSD. (The
# rewrite below also maps Arch's chromium.desktop to www/chromium's
# chromium-browser.desktop.)
PREFIX_SHARE=	applications bash-completion chromium cups fonts fontconfig fzf \
		hermes-desktop hypr icons libretro omarchy-nvim pipewire pixmaps \
		sddm sounds sunshine uwsm vulkan xdg-terminal-exec xournalpp

# FreeBSD implementations of commands whose Arch versions are built on pacman,
# /sys, /proc, NetworkManager or Snapper.
post-extract:
	${CP} ${WRKSRC_freebsd}/freebsd-bin/* ${WRKSRC}/bin/

# The FreeBSD adaptation of Omarchy's sources lives in one script, which the
# port runs here and installs for "omarchy dev link" to run on a checkout.
post-patch:
	${SED} -e 's!%%DATADIR%%!${DATADIR}!g; s!%%PREFIX%%!${PREFIX}!g; s!%%LOCALBASE%%!${LOCALBASE}!g' \
		-e 's!%%PREFIX_SHARE%%!${PREFIX_SHARE:ts|}!g; s!%%GNU_COREUTILS%%!${GNU_COREUTILS:ts|}!g' \
		-e 's!%%PYTHON_CMD%%!${PYTHON_CMD}!g; s!%%PERL%%!${PERL}!g' \
		${WRKSRC_freebsd}/freebsdize.in > ${WRKDIR}/freebsdize
	${LOCALBASE}/bin/bash ${WRKDIR}/freebsdize --in-place ${WRKSRC}

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKDIR}/pdeathsig ${WRKSRC_freebsd}/pdeathsig.c
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKDIR}/session-reaper ${WRKSRC_freebsd}/session-reaper.c
	${MKDIR} ${WRKDIR}/compat ${WRKDIR}/misc
.for f in ${COMPAT_TOOLS}
	${SED} -e 's|%%DATADIR%%|${DATADIR}|g; s|%%PREFIX%%|${PREFIX}|g; s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC_freebsd}/compat/${f} > ${WRKDIR}/compat/${f}
.endfor
.for f in seed-user audio-default profile-omarchy.sh env-freebsd
	${SED} -e 's|%%DATADIR%%|${DATADIR}|g; s|%%PREFIX%%|${PREFIX}|g; s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC_freebsd}/${f} > ${WRKDIR}/misc/${f}
.endfor

do-install:
# Commands, with the ${DATADIR}/bin links Omarchy uses to find them.
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
	cd ${WRKSRC}/bin && for f in *; do \
		${INSTALL_SCRIPT} "$$f" ${STAGEDIR}${PREFIX}/bin/; \
		${RLN} ${STAGEDIR}${PREFIX}/bin/"$$f" ${STAGEDIR}${DATADIR}/bin/"$$f"; \
	done
.for d in ${DATA_DIRS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR}
.endfor
	${RM} -r ${STAGEDIR}${DATADIR}/applications/icons
	${INSTALL_DATA} ${WRKSRC}/version ${WRKSRC}/logo.txt ${WRKSRC}/logo.svg \
		${WRKSRC}/icon.txt ${WRKSRC}/icon.png ${STAGEDIR}${DATADIR}

# FreeBSD support: package map, extra session units, compat tools, GNU links.
	${MKDIR} ${STAGEDIR}${DATADIR}/freebsd/systemd/user/graphical-session.target.wants
	${INSTALL_DATA} ${WRKSRC_freebsd}/freebsd/pkgmap ${WRKSRC_freebsd}/freebsd/pkg.sh ${STAGEDIR}${DATADIR}/freebsd
	for f in ${WRKSRC_freebsd}/systemd-user/*.service; do \
		${SED} -e 's|%%PREFIX%%|${PREFIX}|g' "$$f" > ${STAGEDIR}${DATADIR}/freebsd/systemd/user/$${f##*/}; \
		${LN} -s ../$${f##*/} ${STAGEDIR}${DATADIR}/freebsd/systemd/user/graphical-session.target.wants/$${f##*/}; \
	done
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/omarchy/compat ${STAGEDIR}${PREFIX}/libexec/omarchy/gnubin
	${INSTALL_SCRIPT} ${WRKDIR}/compat/* ${STAGEDIR}${PREFIX}/libexec/omarchy/compat
	${LN} -s ${LOCALBASE}/bin/basuctl ${STAGEDIR}${PREFIX}/libexec/omarchy/compat/busctl
	${INSTALL_SCRIPT} ${WRKDIR}/misc/seed-user ${WRKDIR}/misc/audio-default ${STAGEDIR}${PREFIX}/libexec/omarchy
	${INSTALL_SCRIPT} ${WRKDIR}/freebsdize ${STAGEDIR}${PREFIX}/libexec/omarchy
# For "omarchy dev link": the port's patches and FreeBSD commands, which
# freebsdize applies to a checkout.
	${MKDIR} ${STAGEDIR}${DATADIR}/freebsd/patches ${STAGEDIR}${DATADIR}/freebsd/bin
	${INSTALL_DATA} ${FILESDIR}/patch-* ${STAGEDIR}${DATADIR}/freebsd/patches
	${INSTALL_DATA} ${WRKSRC_freebsd}/freebsd-bin/* ${STAGEDIR}${DATADIR}/freebsd/bin
	${REINPLACE_CMD} -E '1s@^#!(/usr/bin/env bash|/bin/bash)$$@#!${LOCALBASE}/bin/bash@' \
		${STAGEDIR}${DATADIR}/freebsd/bin/*
	${RM} ${STAGEDIR}${DATADIR}/freebsd/bin/*.bak
	${INSTALL_PROGRAM} ${WRKDIR}/pdeathsig ${WRKDIR}/session-reaper ${STAGEDIR}${PREFIX}/libexec/omarchy
.for f in ${GNU_COREUTILS}
	${LN} -s ${LOCALBASE}/bin/g${f} ${STAGEDIR}${PREFIX}/libexec/omarchy/gnubin/${f}
.endfor
.for f in ${GNU_OTHER}
	${LN} -s ${LOCALBASE}/bin/${f:C/.*://} ${STAGEDIR}${PREFIX}/libexec/omarchy/gnubin/${f:C/:.*//}
.endfor

# Session entry points.
	${MKDIR} ${STAGEDIR}${PREFIX}/share/uwsm/env.d ${STAGEDIR}${PREFIX}/share/wayland-sessions
	${INSTALL_DATA} ${WRKDIR}/misc/env-freebsd ${STAGEDIR}${PREFIX}/share/uwsm/env.d/05-omarchy-freebsd
	${INSTALL_DATA} ${WRKSRC}/default/uwsm/env.d/10-omarchy ${STAGEDIR}${PREFIX}/share/uwsm/env.d/10-omarchy
	${SED} -e 's|^Exec=uwsm |Exec=${PREFIX}/libexec/omarchy/compat/uwsm |' \
		-e 's|^TryExec=uwsm$$|TryExec=${PREFIX}/libexec/omarchy/compat/uwsm|' \
		${WRKSRC}/default/wayland-sessions/omarchy.desktop > ${STAGEDIR}${PREFIX}/share/wayland-sessions/omarchy.desktop
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/profile.d
	${INSTALL_DATA} ${WRKDIR}/misc/profile-omarchy.sh ${STAGEDIR}${PREFIX}/etc/profile.d/omarchy.sh
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/pulse/client.conf.d
	${INSTALL_DATA} ${WRKSRC_freebsd}/pulse-client.conf ${STAGEDIR}${PREFIX}/etc/pulse/client.conf.d/50-omarchy.conf
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/polkit-1/rules.d
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC_freebsd}/polkit-omarchy.rules > ${STAGEDIR}${PREFIX}/etc/polkit-1/rules.d/50-omarchy.rules

# Desktop integration defaults.
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xdg-terminal-exec ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${INSTALL_DATA} ${WRKSRC}/default/xdg-terminal-exec/hyprland-xdg-terminals.list ${STAGEDIR}${PREFIX}/share/xdg-terminal-exec
	${INSTALL_DATA} ${WRKSRC}/default/fontconfig/conf.avail/50-omarchy.conf ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
	${RLN} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail/50-omarchy.conf ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/50-omarchy.conf
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fastfetch ${STAGEDIR}${PREFIX}/etc/xdg/kitty
	${INSTALL_DATA} ${WRKSRC}/etc/fastfetch/config.jsonc ${STAGEDIR}${PREFIX}/etc/fastfetch/config.jsonc.sample
	${INSTALL_DATA} ${WRKSRC}/etc/xdg/kitty/kitty.conf ${STAGEDIR}${PREFIX}/etc/xdg/kitty/kitty.conf.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/sudoers.d
.for f in omarchy-passwd-tries omarchy-theme-browser omarchy-tzupdate
	${INSTALL} -m 0440 ${WRKSRC}/etc/sudoers.d/${f} ${STAGEDIR}${PREFIX}/etc/sudoers.d/${f}
.endfor

# Login manager theme and greeter configuration.
	${MKDIR} ${STAGEDIR}${PREFIX}/share/sddm/themes ${STAGEDIR}${PREFIX}/etc/sddm.conf.d
	cd ${WRKSRC}/default/sddm && ${COPYTREE_SHARE} omarchy ${STAGEDIR}${PREFIX}/share/sddm/themes
	${INSTALL_DATA} ${WRKSRC}/default/sddm/hyprland.lua ${STAGEDIR}${PREFIX}/share/sddm
.for f in 10-theme.conf 10-wayland.conf
	${INSTALL_DATA} ${WRKSRC}/etc/sddm.conf.d/${f} ${STAGEDIR}${PREFIX}/etc/sddm.conf.d/${f:S/^10-/10-omarchy-/}
.endfor

# Fonts, icons and branding.
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/default/fonts/omarchy/omarchy.ttf ${STAGEDIR}${FONTSDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps ${STAGEDIR}${PREFIX}/share/pixmaps
	cd ${WRKSRC}/applications/icons && for icon in *; do \
		id=$$(printf '%s\n' "$${icon%.*}" | ${TR} '[:upper:]' '[:lower:]' | ${SED} -E 's/[^[:alnum:]]+/-/g; s/^-//; s/-$$//'); \
		case "$$icon" in \
		*.svg) ${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps; \
			${INSTALL_DATA} "$$icon" ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/$$id.svg ;; \
		*) for size in 48 256; do \
			magick "$$icon" -thumbnail $${size}x$${size} -background transparent -gravity center \
				-extent $${size}x$${size} PNG32:${STAGEDIR}${PREFIX}/share/icons/hicolor/$${size}x$${size}/apps/$$id.png; \
		   done ;; \
		esac; \
	done
	${INSTALL_DATA} ${WRKSRC}/icon.png ${STAGEDIR}${PREFIX}/share/pixmaps/omarchy.png
	${INSTALL_DATA} ${WRKSRC}/icon.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/omarchy.png

# The tree Arch ships in /etc/skel, copied into a user's home by seed-user on
# their first Omarchy session.
	${MKDIR} ${STAGEDIR}${DATADIR}/skel/.config/omarchy/branding \
		${STAGEDIR}${DATADIR}/skel/.local/share/applications \
		${STAGEDIR}${DATADIR}/skel/.local/share/nautilus-python/extensions \
		${STAGEDIR}${DATADIR}/skel/.local/state/omarchy/migrations \
		${STAGEDIR}${DATADIR}/skel/.local/state/omarchy/toggles/hypr \
		${STAGEDIR}${DATADIR}/skel/.local/state/tensaku
	cd ${WRKSRC}/config && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/skel/.config
	${INSTALL_DATA} ${WRKSRC}/logo.txt ${STAGEDIR}${DATADIR}/skel/.config/omarchy/branding/screensaver.txt
	${INSTALL_DATA} ${WRKSRC}/icon.txt ${STAGEDIR}${DATADIR}/skel/.config/omarchy/branding/about.txt
	${INSTALL_DATA} ${WRKSRC}/applications/*.desktop \
		${STAGEDIR}${DATADIR}/skel/.local/share/applications
	${INSTALL_DATA} ${WRKSRC}/default/nautilus-python/extensions/*.py \
		${STAGEDIR}${DATADIR}/skel/.local/share/nautilus-python/extensions
	${INSTALL_DATA} ${WRKSRC}/default/hypr/toggles/flags.lua ${STAGEDIR}${DATADIR}/skel/.local/state/omarchy/toggles/hypr
	${INSTALL_DATA} ${WRKSRC}/default/tensaku/state.toml ${STAGEDIR}${DATADIR}/skel/.local/state/tensaku
	${INSTALL_DATA} ${WRKSRC}/default/bashrc ${STAGEDIR}${DATADIR}/skel/.bashrc
	cd ${WRKSRC}/migrations && for m in *.sh; do \
		${TOUCH} ${STAGEDIR}${DATADIR}/skel/.local/state/omarchy/migrations/$$m; \
	done
# Keep scripts (hooks, first-run steps, shell helpers) executable.
	${FIND} ${STAGEDIR}${DATADIR} -type f ! -path '*/themes/*' -exec ${SH} -c \
		'for f; do head -n 1 "$$f" | grep -q "^#!" && chmod 755 "$$f"; done; true' sh {} +

.include <bsd.port.mk>
