PORTNAME=	daemonarchy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	x11-wm

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	Omarchy desktop on FreeBSD, with Daemonarchy branding and applications
WWW=		https://github.com/jordanhubbard/daemonarchy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	magick:graphics/ImageMagick7 \
		rsvg-convert:graphics/librsvg2-rust

# The Omarchy runtime, the Hyprland session stack and the tools the desktop
# relies on. Arch packages without a FreeBSD equivalent (kernels, firmware,
# DKMS drivers, Limine/Snapper, NetworkManager, BlueZ, power-profiles-daemon)
# are covered by the base system or by the omarchy port's compat layer.
RUN_DEPENDS=	omarchy>0:x11-wm/omarchy \
		egl-wayland>0:graphics/egl-wayland \
		font-awesome>0:x11-fonts/font-awesome \
		fontconfig>0:x11-fonts/fontconfig \
		foot>0:x11/foot \
		gnome-themes-extra>0:x11-themes/gnome-themes-extra \
		grim>0:x11/grim \
		gtk4-layer-shell>0:x11-toolkits/gtk4-layer-shell \
		hyprland-guiutils>0:x11/hyprland-guiutils \
		hyprland-preview-share-picker>0:x11/hyprland-preview-share-picker \
		hyprpicker>0:x11/hyprpicker \
		hyprsunset>0:accessibility/hyprsunset \
		ia-writer-fonts>0:x11-fonts/ia-writer-fonts \
		libsecret>0:security/libsecret \
		mesa-dri>0:graphics/mesa-dri \
		node>0:www/node \
		noto>0:x11-fonts/noto \
		pamixer>0:audio/pamixer \
		pulseaudio>0:audio/pulseaudio \
		${PYTHON_PKGNAMEPREFIX}pygobject>0:devel/py-pygobject@${PY_FLAVOR} \
		qt6-imageformats>0:graphics/qt6-imageformats \
		qt6-wayland>0:graphics/qt6-wayland \
		sddm>0:x11/sddm \
		slurp>0:x11/slurp \
		tensaku>0:graphics/tensaku \
		udiskie>0:sysutils/udiskie \
		bsdisks>0:sysutils/bsdisks \
		${LOCALBASE}/share/uefi-firmware/BHYVE_UEFI.fd:sysutils/edk2@bhyve \
		vm-bhyve>0:sysutils/vm-bhyve \
		tigervnc-viewer>0:net/tigervnc-viewer \
		webp-pixbuf-loader>0:graphics/webp-pixbuf-loader \
		wl-clipboard>0:x11/wl-clipboard \
		wtype>0:x11/wtype \
		xdg-desktop-portal>0:deskutils/xdg-desktop-portal \
		xdg-desktop-portal-gtk>0:x11/xdg-desktop-portal-gtk \
		yaru-icon-theme>0:x11-themes/yaru-icon-theme \
		${LOCALBASE}/lib/spa-0.2/libspa_freebsd_oss.so:audio/pipewire-spa-oss

USES=		python:run
USE_GITHUB=	yes
GH_ACCOUNT=	jordanhubbard
GH_PROJECT=	daemonarchy-desktop

NO_ARCH=	yes

OPTIONS_DEFINE=		APPS BLUETOOTH CLI DEV INPUT OBSIDIAN OMAAPPS PRINT VAAPI
OPTIONS_DEFAULT=	APPS BLUETOOTH CLI DEV INPUT OMAAPPS PRINT VAAPI

APPS_DESC=	Default applications (browser, office, media, notes)
BLUETOOTH_DESC=	Firmware for Realtek and Intel Bluetooth controllers
CLI_DESC=	Terminal tools Omarchy's shell setup expects
DEV_DESC=	Development languages, database clients and container tools
INPUT_DESC=	Fcitx5 input method (XCompose and CJK input)
OBSIDIAN_DESC=	Obsidian notes (proprietary EULA; must be accepted to build)
OMAAPPS_DESC=	Omarchy's own applications (Aether, Omacalc, Omasnap, ...)
PRINT_DESC=	Printing and network service discovery
VAAPI_DESC=	Hardware video decoding drivers

APPS_RUN_DEPENDS=	chromium>0:www/chromium \
			evince>0:graphics/evince \
			ffmpegthumbnailer>0:multimedia/ffmpegthumbnailer \
			gvfs>0:filesystems/gvfs \
			ImageMagick7>0:graphics/ImageMagick7 \
			imv>0:graphics/imv \
			kdenlive>0:multimedia/kdenlive \
			libreoffice>0:editors/libreoffice \
			moonlight-qt>0:games/moonlight-qt \
			mpv>0:multimedia/mpv \
			mpv-mpris>0:multimedia/mpv-mpris \
			nautilus>0:x11-fm/nautilus \
			nautilus-python>0:x11-fm/nautilus-python \
			obs-studio>0:multimedia/obs-studio \
			pinta>0:graphics/pinta \
			sushi>0:x11-fm/sushi \
			tesseract>0:graphics/tesseract \
			tesseract-data>0:graphics/tesseract-data \
			vips>0:graphics/vips \
			xournalpp>0:graphics/xournalpp \
			yt-dlp>0:www/yt-dlp \
			zbar>0:graphics/zbar
BLUETOOTH_RUN_DEPENDS=	iwmbt-firmware>0:comms/iwmbt-firmware \
			rtlbt-firmware>0:comms/rtlbt-firmware
CLI_RUN_DEPENDS=	bash-completion>0:shells/bash-completion \
			bat>0:textproc/bat \
			btop>0:sysutils/btop \
			dua-cli>0:sysutils/dua-cli \
			exfat-utils>0:filesystems/exfat-utils \
			eza>0:sysutils/eza \
			fastfetch>0:sysutils/fastfetch \
			fd-find>0:sysutils/fd \
			fzf>0:textproc/fzf \
			inotify-tools>0:sysutils/inotify-tools \
			inxi>0:sysutils/inxi \
			lazygit>0:devel/lazygit \
			libqrencode>0:graphics/libqrencode \
			neovim>0:editors/neovim \
			omarchy-nvim>0:editors/omarchy-nvim \
			plocate>0:sysutils/plocate \
			ripgrep>0:textproc/ripgrep \
			socat>0:net/socat \
			starship>0:shells/starship \
			tldr>0:sysutils/tldr \
			tmux>0:sysutils/tmux \
			tobi-try>0:devel/tobi-try \
			tzupdate>0:sysutils/tzupdate \
			usage>0:devel/usage \
			whois>0:net/whois \
			zoxide>0:sysutils/zoxide
DEV_USES=		llvm:run lua:51,run ruby:run
DEV_RUN_DEPENDS=	autoconf-archive>0:devel/autoconf-archive \
			docker-buildx>0:sysutils/docker-buildx \
			docker-compose>0:sysutils/docker-compose \
			dotnet>0:lang/dotnet \
			fakeroot>0:security/fakeroot \
			lazydocker>0:sysutils/lazydocker \
			libyaml>0:textproc/libyaml \
			${LUA_PKGNAMEPREFIX}luarocks>0:devel/lua-luarocks@${LUA_FLAVOR} \
			mariadb118-client>0:databases/mariadb118-client \
			mise>0:sysutils/mise \
			postgresql18-client>0:databases/postgresql18-client \
			${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR} \
			tree-sitter-cli>0:devel/tree-sitter-cli
INPUT_RUN_DEPENDS=	fcitx5>0:textproc/fcitx5 \
			fcitx5-gtk3>0:textproc/fcitx5-gtk \
			fcitx5-qt6>0:textproc/fcitx5-qt
OBSIDIAN_RUN_DEPENDS=	obsidian>0:textproc/obsidian
OMAAPPS_RUN_DEPENDS=	aether>0:x11-themes/aether \
			cliamp>0:audio/cliamp \
			herdr>0:sysutils/herdr \
			omacalc>0:math/omacalc \
			omacut>0:multimedia/omacut \
			omasnap>0:graphics/omasnap \
			omawrite>0:editors/omawrite \
			owe>0:x11/owe \
			owe-lockfeed>0:x11/owe-lockfeed \
			ttfx>0:misc/ttfx
PRINT_RUN_DEPENDS=	avahi>0:net/avahi \
			cups>0:print/cups \
			cups-filters>0:print/cups-filters \
			cups-pk-helper>0:print/cups-pk-helper \
			nss_mdns>0:dns/nss_mdns \
			system-config-printer>0:print/system-config-printer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVAAPI} && (${ARCH} == amd64 || ${ARCH} == i386)
RUN_DEPENDS+=	libva-intel-driver>0:multimedia/libva-intel-driver \
		libva-intel-media-driver>0:multimedia/libva-intel-media-driver \
		libvpl>0:multimedia/libvpl
.endif

# Daemonarchy's own identity. Omarchy's files stay as Omarchy ships them; these
# sit beside them: defaults that seed-user copies into a new home ahead of
# Omarchy's, and a login theme that reuses Omarchy's with its own wordmark.
SKEL=		${PREFIX}/share/omarchy/skel.d/daemonarchy
SDDM_THEME=	${PREFIX}/share/sddm/themes/daemonarchy
SDDM_SHARED=	Main.qml theme.conf bullet.png entry.png entry-failed.png \
		lock.png lock-failed.png
# FreeBSD's own features, under System > FreeBSD in the menu: boot
# environments, jails, bhyve VMs, home snapshots, and DTrace.
COMMANDS=	daemonarchy-be daemonarchy-dev-setup daemonarchy-dtrace \
		daemonarchy-home-snapshots daemonarchy-jail daemonarchy-vm

do-build:
	rsvg-convert -w 3840 -h 2160 ${WRKSRC}/wallpaper.svg | \
		magick png:- -quality 92 ${WRKDIR}/0-daemonarchy.jpg
	rsvg-convert -w 800 ${WRKSRC}/wordmark.svg -o ${WRKDIR}/logo.png
	${MKDIR} ${WRKDIR}/bin
.for f in ${COMMANDS} daemonarchy.cron
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g; s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/${f} > ${WRKDIR}/bin/${f}
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${SKEL}/.config/omarchy/branding \
		${STAGEDIR}${SKEL}/.config/omarchy/backgrounds/tokyo-night
	${INSTALL_DATA} ${WRKSRC}/screensaver.txt ${WRKSRC}/about.txt \
		${STAGEDIR}${SKEL}/.config/omarchy/branding
	${INSTALL_DATA} ${WRKDIR}/0-daemonarchy.jpg \
		${STAGEDIR}${SKEL}/.config/omarchy/backgrounds/tokyo-night
	${MKDIR} ${STAGEDIR}${SDDM_THEME}
	${INSTALL_DATA} ${WRKDIR}/logo.png ${WRKSRC}/metadata.desktop ${STAGEDIR}${SDDM_THEME}
.for f in ${SDDM_SHARED}
	${LN} -s ../omarchy/${f} ${STAGEDIR}${SDDM_THEME}/${f}
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/sddm.conf.d
	${INSTALL_DATA} ${WRKSRC}/20-daemonarchy-theme.conf ${STAGEDIR}${PREFIX}/etc/sddm.conf.d
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/mark.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/daemonarchy.svg
.for f in ${COMMANDS}
	${INSTALL_SCRIPT} ${WRKDIR}/bin/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/omarchy/vendor ${STAGEDIR}${PREFIX}/etc/cron.d
	${INSTALL_DATA} ${WRKSRC}/omarchy-menu.jsonc ${STAGEDIR}${PREFIX}/share/omarchy/vendor
	${INSTALL_DATA} ${WRKDIR}/bin/daemonarchy.cron ${STAGEDIR}${PREFIX}/etc/cron.d/daemonarchy
	${MKDIR} ${STAGEDIR}${DATADIR}
	${ECHO_CMD} ${PORTVERSION} > ${STAGEDIR}${DATADIR}/version

.include <bsd.port.mk>
