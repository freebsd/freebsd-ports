PORTNAME=	nscde
DISTVERSION=	1.4
CATEGORIES=	x11-wm

MAINTAINER=	freebsd@ny-central.org
COMMENT=	Modern CDE clone based on fvwm

LICENSE=	GPLv3

PATCH_DEPENDS=	gsed:textproc/gsed \
		ksh93:shells/ast-ksh
BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
		xsltproc:textproc/libxslt
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=5.7.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR} \
		convert:graphics/ImageMagick${IMAGEMAGICK_DEFAULT} \
		dunst:sysutils/dunst \
		font-bh-lucidatypewriter-100dpi>0:x11-fonts/font-bh-lucidatypewriter-100dpi \
		fvwm2:x11-wm/fvwm2 \
		gsed:textproc/gsed \
		ksh93:shells/ast-ksh \
		pyuic5:devel/py-qt5@${PY_FLAVOR} \
		qt5-style-plugins>=5.0.0:x11-themes/qt5-style-plugins \
		roboto-fonts-ttf>0:x11-fonts/roboto-fonts-ttf \
		stalonetray:x11/stalonetray \
		xdotool:x11/xdotool \
		xdpyinfo:x11/xdpyinfo \
		xrdb:x11/xrdb \
		xrefresh:x11/xrefresh \
		xscreensaver:x11/xscreensaver \
		xsettingsd:x11/xsettingsd \
		xterm:x11/xterm

USES=		gettext pkgconfig:build python:3.7+ shebangfix xorg
USE_GITHUB=	yes
GH_ACCOUNT=	nscde
USE_XORG=	x11 xext xpm xrandr

SHEBANG_FILES=	Installer.ksh NsCDE/bin/confget.py NsCDE/bin/confset.py \
		NsCDE/bin/nscde_usleep NsCDE/bin/sysinfo.py \
		NsCDE/lib/python/Globals.py NsCDE/lib/python/MiscFun.py \
		NsCDE/lib/python/MotifColors.py NsCDE/lib/python/Opts.py \
		NsCDE/lib/python/SpritesGtk2.py NsCDE/lib/python/Theme.py \
		NsCDE/lib/python/ThemeGtk.py NsCDE/libexec/colorconv.py \
		NsCDE/libexec/geticon.py NsCDE/libexec/getla1.py \
		NsCDE/libexec/nscde_palette_colorgen.py \
		NsCDE/libexec/themegen.py \
		NsCDE/share/config_templates/integration/gtk2_gtk3_qt/gtk-2.0/img/SpritesGtk2.py \
		NsCDE/share/config_templates/integration/gtk2_gtk3_qt/gtk-2.0/img/src/SpritesGtk2.py

DOCSDIR=	${PREFIX}/share/doc/nscde

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	DOCS EXAMPLES SUDO KSH2020
OPTIONS_SINGLE=	ROOTAUTH IMGMAG KSHOPT
OPTIONS_SINGLE_KSHOPT=		ASTKSH KSH2020
OPTIONS_SINGLE_ROOTAUTH=	SUDO DOAS
ASTKSH_DESC=	AT&T KSH93
DOAS_DESC=	Use doas to elevate privileges
KSH2020_DESC=	Updated AT&T KSH93 (arm64 compatible)
KSHOPT_DESC=	KSH version
ROOTAUTH_DESC=	Root authorization
SUDO_DESC=	Use sudo to elevate privileges

ASTKSH_RUN_DEPENDS=	ksh93:shells/ast-ksh93
DOAS_RUN_DEPENDS=	doas:security/doas
KSH2020_RUN_DEPENDS=	ksh93:shells/ksh2020
SUDO_RUN_DEPENDS=	sudo:security/sudo

_NSCDE_HELPERS=	GWM.sh Notifier.sh Splash.sh appfinder backdropmgr colorconv.py \
		colormgr fontmgr fp_manage_subpanel fpexec fpseticon \
		generate_app_menus generate_subpanels geticon.py getla1.py \
		keymenu nscde-acpi nscde_get_logical_screens \
		nscde_palette_colorgen.py nscde_setup strip_icon_path \
		style_managers.shlib subpanel_menuitem_props themegen.py \
		xrandr_backer

_PREFIX_FILES=	NsCDE/bin/get_fvwm_infostore \
		NsCDE/bin/getfont NsCDE/bin/mkpagemenu NsCDE/bin/nscde \
		NsCDE/bin/nscde_colorpicker NsCDE/bin/xdowrapper \
		NsCDE/config/NsCDE-Main.conf.sample NsCDE/libexec/Splash.sh \
		NsCDE/libexec/fp_manage_subpanel \
		NsCDE/libexec/fvwm-modules/FvwmScript NsCDE/libexec/nscde_setup \
		NsCDE/libexec/themegen.py \
		NsCDE/share/doc/examples/lxsession-integration/desktop.conf \
		NsCDE/share/doc/examples/mate-session-integration/nscde.desktop \
		NsCDE/share/doc/examples/sudo/006_PowerManager \
		NsCDE/share/doc/examples/xsession-integration/nscde.desktop \
		docbook/NsCDE.xml docbook/NsCDE.xsl

_SHAREDOC=	NsCDE/config/FrontPanel.actions \
		NsCDE/config/NsCDE-Keybindings.conf \
		NsCDE/config/NsCDE-Menus.conf NsCDE/config/NsCDE-Subpanels.conf \
		NsCDE/config/Subpanels.actions NsCDE/lib/scripts/BackdropMgr \
		NsCDE/lib/scripts/BeepMgr NsCDE/lib/scripts/CheckMailApplet \
		NsCDE/lib/scripts/ColorMgr NsCDE/lib/scripts/ExecDialog \
		NsCDE/lib/scripts/FontMgr NsCDE/lib/scripts/FpLite \
		NsCDE/lib/scripts/GeometryMgr NsCDE/libexec/GWM.sh \
		NsCDE/lib/scripts/GWMOptions NsCDE/lib/scripts/KeyboardMgr \
		NsCDE/lib/scripts/ModifyColor NsCDE/lib/scripts/MonthDayApplet \
		NsCDE/lib/scripts/NColorsDialog NsCDE/lib/scripts/NProcMgr \
		NsCDE/lib/scripts/Occupy NsCDE/lib/scripts/PaletteDialog \
		NsCDE/lib/scripts/PointerMgr NsCDE/lib/scripts/PowerSaveMgr \
		NsCDE/lib/scripts/StyleMgr NsCDE/lib/scripts/SubpanelMgr \
		NsCDE/lib/scripts/SysActionDialog \
		NsCDE/lib/scripts/SubpanelSettings NsCDE/lib/scripts/Sysinfo \
		NsCDE/lib/scripts/WSM NsCDE/lib/scripts/WSM-2 \
		NsCDE/lib/scripts/WSM-4 NsCDE/lib/scripts/WSM-6 \
		NsCDE/lib/scripts/WSM-8 NsCDE/lib/scripts/WindowMgr \
		NsCDE/lib/scripts/WsPgMgr

_CURLYICONS=	NsCDE/config/NsCDE-Functions.conf NsCDE/libexec/colormgr \
		NsCDE/libexec/subpanel_menuitem_props

_SHARESLASH=	NsCDE/config/NsCDE-Backdrops.conf \
		NsCDE/config/NsCDE-Functions.conf NsCDE/config/NsCDE-Main.conf \
		NsCDE/share/doc/NsCDE.txt \
		NsCDE/share/doc/html/NsCDE-Localization.html

_BSHARESLASH=	NsCDE/config/NsCDE-Functions.conf NsCDE/lib/scripts/BackdropMgr \
		NsCDE/lib/scripts/BeepMgr NsCDE/lib/scripts/ColorMgr \
		NsCDE/lib/scripts/ExecDialog NsCDE/lib/scripts/FilePicker \
		NsCDE/lib/scripts/FontMgr NsCDE/lib/scripts/GeometryMgr \
		NsCDE/libexec/GWM.sh NsCDE/lib/scripts/GWMOptions \
		NsCDE/lib/scripts/InputForm NsCDE/lib/scripts/KeyboardMgr \
		NsCDE/lib/scripts/ModifyColor NsCDE/lib/scripts/NColorsDialog \
		NsCDE/lib/scripts/NProcMgr NsCDE/lib/scripts/Occupy \
		NsCDE/lib/scripts/PaletteDialog NsCDE/lib/scripts/PointerMgr \
		NsCDE/lib/scripts/PowerSaveMgr NsCDE/lib/scripts/StyleMgr \
		NsCDE/lib/scripts/SubpanelMgr NsCDE/lib/scripts/SysActionDialog \
		NsCDE/lib/scripts/SubpanelSettings NsCDE/lib/scripts/Sysinfo \
		NsCDE/lib/scripts/WSM NsCDE/lib/scripts/WSM-2 \
		NsCDE/lib/scripts/WSM-4 NsCDE/lib/scripts/WSM-6 \
		NsCDE/lib/scripts/WSM-8 NsCDE/lib/scripts/WindowMgr \
		NsCDE/lib/scripts/WsPgMgr NsCDE/libexec/Notifier.sh \
		NsCDE/libexec/appfinder NsCDE/libexec/fontmgr \
		NsCDE/libexec/strip_icon_path \
		NsCDE/libexec/subpanel_menuitem_props \
		NsCDE/share/config_templates/colormgr.local \
		NsCDE/share/doc/NsCDE.txt README.localization \
		NsCDE/bin/fpclock

_CSHARESLASH=	NsCDE/libexec/colormgr NsCDE/libexec/fontmgr \
		NsCDE/libexec/style_managers.shlib \
		NsCDE/libexec/subpanel_menuitem_props \
		NsCDE/bin/fpclock NsCDE/share/config_templates/colormgr.local

_SHARENSLASH=	NsCDE/config/NsCDE-Main.conf

_LIBEXEC_SCRIPTS=	NsCDE/config/NsCDE-Functions.conf \
			NsCDE/config/NsCDE-Main.conf \
			NsCDE/config/NsCDE-Menus.conf \
			NsCDE/lib/scripts/ColorMgr \
			NsCDE/lib/scripts/ModifyColor \
			NsCDE/bin/fpclock

_BLIBEXEC_SCRIPTS=	NsCDE/lib/scripts/BackdropMgr \
			NsCDE/lib/scripts/ColorMgr NsCDE/lib/scripts/FontMgr \
			NsCDE/lib/scripts/FpLite NsCDE/lib/scripts/GeometryMgr \
			NsCDE/lib/scripts/ModifyColor \
			NsCDE/lib/scripts/PaletteDialog \
			NsCDE/lib/scripts/SubpanelMgr \
			NsCDE/lib/scripts/SysActionDialog \
			NsCDE/lib/scripts/SubpanelSettings \
			NsCDE/libexec/colormgr \
			NsCDE/libexec/subpanel_menuitem_props \
			NsCDE/share/config_templates/colormgr.local \
			NsCDE/share/doc/NsCDE.txt \
			NsCDE/bin/fpclock

_CLIBEXEC_SCRIPTS=	NsCDE/libexec/backdropmgr NsCDE/libexec/colormgr

_CLIBS=		NsCDE/libexec/colormgr

_LIBS=		NsCDE/config/NsCDE-Main.conf

_BBINS=		NsCDE/config/FrontPanel.actions \
		NsCDE/config/NsCDE-Main.conf.sample \
		NsCDE/config/NsCDE-Functions.conf.sample \
		NsCDE/lib/scripts/ActionForm NsCDE/lib/scripts/BackdropMgr \
		NsCDE/lib/scripts/BeepMgr NsCDE/lib/scripts/ChoiceForm \
		NsCDE/lib/scripts/ColorMgr NsCDE/lib/scripts/ExecDialog \
		NsCDE/lib/scripts/FilePicker NsCDE/lib/scripts/FontMgr \
		NsCDE/lib/scripts/GeometryMgr NsCDE/lib/scripts/InputForm \
		NsCDE/lib/scripts/KeyboardMgr NsCDE/lib/scripts/ModifyColor \
		NsCDE/lib/scripts/MonthDayApplet \
		NsCDE/lib/scripts/NColorsDialog NsCDE/lib/scripts/NProcMgr \
		NsCDE/lib/scripts/Occupy NsCDE/lib/scripts/PaletteDialog \
		NsCDE/lib/scripts/PointerMgr NsCDE/lib/scripts/PowerSaveMgr \
		NsCDE/lib/scripts/StyleMgr NsCDE/lib/scripts/SubpanelMgr \
		NsCDE/lib/scripts/SysActionDialog \
		NsCDE/lib/scripts/SubpanelSettings NsCDE/lib/scripts/Sysinfo \
		NsCDE/lib/scripts/WSM NsCDE/lib/scripts/WSM-2 \
		NsCDE/lib/scripts/WSM-4 NsCDE/lib/scripts/WSM-6 \
		NsCDE/lib/scripts/WSM-8 NsCDE/lib/scripts/WaitNotice \
		NsCDE/lib/scripts/WindowMgr NsCDE/lib/scripts/WsPgMgr \
		NsCDE/libexec/Notifier.sh NsCDE/libexec/backdropmgr \
		NsCDE/libexec/colormgr NsCDE/libexec/fontmgr \
		NsCDE/libexec/fp_manage_subpanel NsCDE/libexec/strip_icon_path \
		NsCDE/libexec/subpanel_menuitem_props \
		NsCDE/libexec/GWM.sh \
		NsCDE/share/applications/NsCDE-Exec.desktop \
		NsCDE/share/applications/NsCDE-FvwmConsole.desktop \
		NsCDE/share/applications/NsCDE-NProcMgr.desktop \
		NsCDE/share/applications/NsCDE-StyleMgr.desktop \
		NsCDE/share/applications/NsCDE-Sysinfo.desktop \
		NsCDE/share/applications/NsCDE-WsPgMgr.desktop \
		NsCDE/share/applications/WatchErrors.desktop \
		NsCDE/share/doc/NsCDE.txt NsCDE/lib/scripts/GWMOptions \
		NsCDE/share/applications/NsCDE-GWM.desktop

_SBINS=		NsCDE/config/NsCDE-FrontPanel.conf \
		NsCDE/config/NsCDE-Functions.conf NsCDE/config/NsCDE-Main.conf \
		NsCDE/lib/scripts/WSM NsCDE/lib/scripts/WSM-2 \
		NsCDE/lib/scripts/WSM-4 NsCDE/lib/scripts/WSM-6 \
		NsCDE/lib/scripts/WSM-8 NsCDE/lib/scripts/WsPgMgr

_CONFREF=	NsCDE/config/NsCDE-Main.conf

_CCONFIGS=	NsCDE/libexec/colormgr

_CONFIGS=	NsCDE/lib/scripts/SubpanelMgr \
		NsCDE/lib/scripts/SubpanelSettings \
		NsCDE/lib/scripts/WindowMgr NsCDE/lib/scripts/WsPgMgr \
		NsCDE/libexec/fp_manage_subpanel NsCDE/libexec/fpexec \
		NsCDE/libexec/fpseticon NsCDE/libexec/generate_app_menus \
		NsCDE/libexec/generate_subpanels NsCDE/libexec/keymenu \
		NsCDE/libexec/subpanel_menuitem_props NsCDE/share/doc/NsCDE.txt \
		README.md

_KSHFIX=	NsCDE/bin/fpclock NsCDE/bin/get_fvwm_infostore NsCDE/bin/getdpi \
		NsCDE/bin/getfont NsCDE/bin/ised NsCDE/bin/mkpagemenu \
		NsCDE/bin/nscde NsCDE/bin/nscde_colorpicker \
		NsCDE/bin/nscde_fvwmclnt NsCDE/bin/nscde_var_append \
		NsCDE/bin/xdowrapper NsCDE/libexec/Notifier.sh \
		NsCDE/libexec/GWM.sh \
		NsCDE/libexec/Splash.sh NsCDE/libexec/appfinder \
		NsCDE/libexec/backdropmgr NsCDE/libexec/colormgr \
		NsCDE/libexec/fontmgr NsCDE/libexec/fp_manage_subpanel \
		NsCDE/libexec/fpexec NsCDE/libexec/fpseticon \
		NsCDE/libexec/fvwm-modules/FvwmScript \
		NsCDE/libexec/generate_app_menus \
		NsCDE/libexec/generate_subpanels NsCDE/libexec/keymenu \
		NsCDE/libexec/nscde-acpi \
		NsCDE/libexec/nscde_get_logical_screens \
		NsCDE/libexec/strip_icon_path \
		NsCDE/libexec/subpanel_menuitem_props \
		NsCDE/share/config_templates/colormgr.local \
		NsCDE/share/config_templates/fontmgr.local generate_subpanels

post-extract:
	${MV} ${WRKDIR}/NsCDE-${DISTVERSION} ${WRKDIR}/${PORTNAME}-${DISTVERSION}

post-patch:
	${CP} ${WRKSRC}/NsCDE/libexec/generate_subpanels ${WRKSRC}/generate_subpanels
	${REINPLACE_CMD} -e 's@config/@etc/nscde/@g' ${WRKSRC}/generate_subpanels
	( for SDOC in ${_SHAREDOC}; do ${REINPLACE_CMD} -e 's@$$\[NSCDE_ROOT\]/share/doc/@'${PREFIX}'/share/doc/nscde/@g' ${WRKSRC}/$${SDOC}; done )
	${REINPLACE_CMD} -e 's@\\/@/@g' ${WRKSRC}/NsCDE/libexec/GWM.sh
	( for SDOC in ${_SHARESLASH}; do ${REINPLACE_CMD} -e 's@$$\[NSCDE_ROOT\]/share/@'${DATADIR}'/@g' ${WRKSRC}/$${SDOC}; done )
	( for SDOC in ${_SHARENSLASH}; do ${REINPLACE_CMD} -e 's@$$\[NSCDE_ROOT\]/share@'${DATADIR}'@g' ${WRKSRC}/$${SDOC}; done )
	( for SCR in ${_LIBEXEC_SCRIPTS}; do ${REINPLACE_CMD} -e 's@$$\[NSCDE_ROOT\]/libexec/@'${PREFIX}'/libexec/nscde/@g' ${WRKSRC}/$${SCR}; done )
	( for SLIB in ${_LIBS}; do ${REINPLACE_CMD} -e "s@$$\[NSCDE_ROOT\]/lib/@${PREFIX}/lib/nscde/@g" ${WRKSRC}/$${SLIB}; done )
	( for SB in ${_SBINS}; do ${REINPLACE_CMD} -e 's@$$\[NSCDE_ROOT\]/bin/@'${PREFIX}'/sbin/@g' ${WRKSRC}/$${SB}; done )
	( for CR in ${_CONFREF}; do ${REINPLACE_CMD} -e 's@$$\[NSCDE_ROOT\]/config/@'${ETCDIR}'/@g' ${WRKSRC}/$${CR}; done )
	( for IDOC in ${_CURLYICONS}; do ${REINPLACE_CMD} -e 's@$${NSCDE_ROOT}/share/icons/@'${PREFIX}'/share/icons/@g' ${WRKSRC}/$${IDOC}; done )
	( for SDOC in ${_CSHARESLASH}; do ${REINPLACE_CMD} -e 's@$${NSCDE_ROOT}/share/@'${DATADIR}'/@g' ${WRKSRC}/$${SDOC}; done )
	( for SDOC in ${_BSHARESLASH}; do ${REINPLACE_CMD} -e 's@$$NSCDE_ROOT/share/@'${DATADIR}'/@g' ${WRKSRC}/$${SDOC}; done )
	${FIND} ${WRKSRC}/NsCDE/config -type f -name '*.conf' -exec ${MV} {} {}.sample \;
	${FIND} ${WRKSRC}/NsCDE/config -type f -name '*.menu' -exec ${MV} {} {}.sample \;
	( for BBIN in ${_BBINS}; do ${REINPLACE_CMD} -e 's@$$NSCDE\_ROOT\/bin@'${PREFIX}'/sbin@g' ${WRKSRC}/$${BBIN}; done )
	( for CFG in ${_CONFIGS}; do ${REINPLACE_CMD} -e 's@$$NSCDE\_ROOT\/config@'${ETCDIR}'@g' ${WRKSRC}/$${CFG}; done )
	( for SCR in ${_BLIBEXEC_SCRIPTS}; do ${REINPLACE_CMD} -e 's@$$NSCDE\_ROOT\/libexec@'${PREFIX}'/libexec/nscde@g' ${WRKSRC}/$${SCR}; done )
	( for CFG in ${_CCONFIGS}; do ${REINPLACE_CMD} -e 's@$${NSCDE_ROOT}/config/@'${ETCDIR}'/@g' ${WRKSRC}/$${CFG}; done )
	( for SLIB in ${_CLIBEXEC_SCRIPTS}; do ${REINPLACE_CMD} -e 's@$${NSCDE_ROOT}/libexec/@'${PREFIX}'/libexec/nscde/@g' ${WRKSRC}/$${SLIB}; done )
	( for CLIB in ${_CLIBS}; do ${REINPLACE_CMD} -e 's@$${NSCDE_ROOT}/lib/@'${PREFIX}'/lib/nscde/@g' ${WRKSRC}/$${CLIB}; done )
	${WRKSRC}/NsCDE/bin/ised -c 's/\*FrontPanel: \(.*x.*\), Id NsCDE-Subpanel\(.*\), Frame 1, PressColorset 27, \\/\*FrontPanel: \1, Id NsCDE-Subpanel\2, Frame 1, PressColorset 27, \\\n  Icon NsCDE\/FPSubArrowUp.xpm, PressIcon NsCDE\/FPSubArrowDown.xpm, \\/g' -f "${WRKSRC}/NsCDE/config/NsCDE-FrontPanel.conf.sample"
	( for KSHB in ${_KSHFIX}; do ${REINPLACE_CMD} -e 's@^#!/usr/bin/env ksh93@#!'${PREFIX}'/bin/ksh93@' ${WRKSRC}/$${KSHB}; done )
	${FIND} ${WRKSRC}/NsCDE -type f -name '*.bak' -delete
	( for HLP in ${_PREFIX_FILES}; do ${REINPLACE_CMD} -e 's@$${PREFIX}@'${PREFIX}'@g' ${WRKSRC}/$${HLP}; done )
	${REINPLACE_CMD} -e 's@$$NSCDE\_ROOT@${PREFIX}@g' ${WRKSRC}/NsCDE/bin/fpclock
	${REINPLACE_CMD} -e 's@-$${NSCDE_OS}\_$${MARCH}@@g' ${WRKSRC}/NsCDE/bin/fpclock
	${FIND} ${WRKSRC}/NsCDE -type f -name '*.bak' -delete
	${MV} ${WRKSRC}/NsCDE/share/config_templates/colormgr.local ${WRKSRC}/NsCDE/share/doc/examples/colormgr.local.sample
	${REINPLACE_CMD} -e 's@export NSCDE\_VERSION=\"1.3\"@export NSCDE_VERSION=\"'${DISTVERSION}'\"@g' ${WRKSRC}/NsCDE/bin/nscde

post-patch-DOAS-on:
	${REINPLACE_CMD} -e 's@sudo@doas@g' ${WRKSRC}/NsCDE/lib/scripts/SysActionDialog
	${REINPLACE_CMD} -e 's@sudo@doas@g' ${WRKSRC}/NsCDE/config/NsCDE-Functions.conf.sample
	${REINPLACE_CMD} -e 's@$${PREFIX}@'${PREFIX}'@g' ${WRKSRC}/NsCDE/share/doc/examples/doas.conf
	${FIND} ${WRKSRC}/NsCDE -type f -name '*.bak' -delete

do-build:
	${RM} ${WRKSRC}/NsCDE/share/doc/html/*
	(cd ${WRKSRC}/docbook && ${PREFIX}/bin/xsltproc -o ${WRKSRC}/NsCDE/share/doc/html/NsCDE.html NsCDE.xsl NsCDE.xml)
	${CP} ${WRKSRC}/docbook/NsCDE.css ${WRKSRC}/NsCDE/share/doc/html/NsCDE.css
	make -C ${WRKSRC}/src/XOverrideFontCursor
	make -C ${WRKSRC}/src/pclock-0.13.1/src
	make -C ${WRKSRC}/src/colorpicker
	${STRIP_CMD} ${WRKSRC}/src/colorpicker/colorpicker
	${STRIP_CMD} ${WRKSRC}/src/pclock-0.13.1/src/pclock
	${STRIP_CMD} ${WRKSRC}/src/XOverrideFontCursor/XOverrideFontCursor.so

do-install:
	${FIND} ${WRKSRC} -type f -name '*.orig' -delete
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/nscde/fvwm-modules
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/nscde
	${MKDIR} ${STAGEDIR}/${ETCDIR}/xdg/menus
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/icons/NsCDE
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/nscde
	${INSTALL_DATA} ${WRKSRC}/NsCDE/config/*.sample ${STAGEDIR}/${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/NsCDE/config/*.actions ${STAGEDIR}/${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/NsCDE/config/xdg/menus/* ${STAGEDIR}/${ETCDIR}/xdg/menus
	${INSTALL_DATA} ${WRKSRC}/src/XOverrideFontCursor/XOverrideFontCursor.so ${STAGEDIR}/${PREFIX}/lib/nscde
	${INSTALL_PROGRAM} ${WRKSRC}/src/pclock-0.13.1/src/pclock ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/colorpicker/colorpicker ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/NsCDE/bin/* ${STAGEDIR}/${PREFIX}/sbin
	( for HLP in ${_NSCDE_HELPERS}; do ${INSTALL_SCRIPT} ${WRKSRC}/NsCDE/libexec/$${HLP} ${STAGEDIR}/${PREFIX}/libexec/nscde/$${HLP}; done )
	${INSTALL_SCRIPT} ${WRKSRC}/NsCDE/libexec/fvwm-modules/FvwmScript ${STAGEDIR}/${PREFIX}/libexec/nscde/fvwm-modules
	(cd ${WRKSRC}/NsCDE/share/icons && ${COPYTREE_SHARE} . ${STAGEDIR}/${PREFIX}/share/icons)
	${INSTALL_DATA} ${WRKSRC}/NsCDE/share/applications/* ${STAGEDIR}/${PREFIX}/share/applications
	(cd ${WRKSRC}/NsCDE/share && ${COPYTREE_SHARE} "palettes photos config_templates backdrops defaults desktop-directories locale \
		fontsets fallback" ${STAGEDIR}/${DATADIR})
	(cd ${WRKSRC}/NsCDE/lib && ${COPYTREE_SHARE} . ${STAGEDIR}/${PREFIX}/lib/nscde)
	NSCDE_ROOT="${STAGEDIR}/${PREFIX}" HAS_WINDOWNAME=1 SYSMODE=1 ${WRKSRC}/generate_subpanels > ${STAGEDIR}/${ETCDIR}/NsCDE-Subpanels.conf.sample
	${FIND} ${STAGEDIR}/${ETCDIR} -type f -name '*.actions' -exec ${MV} {} {}.sample \;

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/doc/nscde
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/examples/nscde
	(cd ${WRKSRC}/NsCDE/share/doc/examples && ${COPYTREE_SHARE} . ${STAGEDIR}/${PREFIX}/share/examples/nscde)
	(cd ${WRKSRC}/NsCDE/share/doc && ${COPYTREE_SHARE} html ${STAGEDIR}/${PREFIX}/share/doc/nscde)
	(cd ${WRKSRC}/NsCDE/share/doc && ${COPYTREE_SHARE} help ${STAGEDIR}/${PREFIX}/share/doc/nscde)
	${INSTALL_DATA} ${WRKSRC}/NsCDE/share/doc/NsCDE.* ${STAGEDIR}/${PREFIX}/share/doc/nscde

.include <bsd.port.mk>
