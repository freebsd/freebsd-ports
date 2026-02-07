PORTNAME=	nscde
DISTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	https://github.com/NsCDE/NsCDE/releases/download/${DISTVERSION}/

MAINTAINER=	freebsd@ny-central.org
COMMENT=	Modern CDE clone based on fvwm
WWW=		https://github.com/NsCDE/NsCDE

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=5.7.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.11:devel/py-pyyaml@${PY_FLAVOR} \
		dunst:sysutils/dunst \
		font-bh-lucidatypewriter-100dpi>0:x11-fonts/font-bh-lucidatypewriter-100dpi \
		fvwm2:x11-wm/fvwm2 \
		gsed:textproc/gsed \
		ksh93:shells/ksh \
		qt5-style-plugins>=5.0.0:x11-themes/qt5-style-plugins \
		roboto-fonts-ttf>0:x11-fonts/roboto-fonts-ttf \
		stalonetray:x11/stalonetray \
		xclip:x11/xclip \
		xdotool:x11/xdotool \
		xdpyinfo:x11/xdpyinfo \
		xrandr>0:x11/xrandr \
		xrdb:x11/xrdb \
		xrefresh:x11/xrefresh \
		xscreensaver:x11/xscreensaver \
		xsettingsd:x11/xsettingsd \
		xterm:x11/xterm
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=5.7.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.11:devel/py-pyyaml@${PY_FLAVOR} \
		dunst:sysutils/dunst \
		font-bh-lucidatypewriter-100dpi>0:x11-fonts/font-bh-lucidatypewriter-100dpi \
		fvwm2:x11-wm/fvwm2 \
		gsed:textproc/gsed \
		qt5-style-plugins>=5.0.0:x11-themes/qt5-style-plugins \
		roboto-fonts-ttf>0:x11-fonts/roboto-fonts-ttf \
		stalonetray:x11/stalonetray \
		xclip:x11/xclip \
		xdotool:x11/xdotool \
		xdpyinfo:x11/xdpyinfo \
		xrandr>0:x11/xrandr \
		xrdb:x11/xrdb \
		xrefresh:x11/xrefresh \
		xscreensaver:x11/xscreensaver \
		xsettingsd:x11/xsettingsd \
		xterm:x11/xterm

USES=		desktop-file-utils gettext magick pkgconfig:build pyqt:5 \
		python shebangfix xorg
USE_PYQT=	pyqt5
USE_XORG=	x11 xext xpm

SHEBANG_FILES=	doc/examples/fvwm3-per-monitor/nitrowrapper

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-python-shebang="${PYTHON_CMD}"

DOCSDIR=	${PREFIX}/share/doc/nscde
SUB_FILES=	pkg-message
SUB_LIST=	EXAMPLESDIR=${EXAMPLESDIR} \
		PREFIX=${PREFIX}

WRKSRC=		${WRKDIR}/NsCDE-${DISTVERSION}

OPTIONS_DEFINE=			DOCS EXAMPLES
OPTIONS_DEFAULT=		DOCS EXAMPLES KSH2020 SUDO
OPTIONS_SINGLE=			IMGMAG KSHOPT ROOTAUTH
OPTIONS_SINGLE_KSHOPT=		ASTKSH KSH2020
OPTIONS_SINGLE_ROOTAUTH=	DOAS SUDO
ASTKSH_DESC=			AT&T KSH93
DOAS_DESC=			Use doas to elevate privileges
KSH2020_DESC=			Updated AT&T KSH93 (arm64 compatible)
KSHOPT_DESC=			KSH version
ROOTAUTH_DESC=			Root authorization
SUDO_DESC=			Use sudo to elevate privileges

ASTKSH_RUN_DEPENDS=	ksh93:shells/ast-ksh93
DOAS_RUN_DEPENDS=	doas:security/doas
KSH2020_RUN_DEPENDS=	ksh93:shells/ksh

SUDO_USES=	sudo

_SUDOFILES=	data/fvwm/Functions.fvwmconf.in lib/scripts/SysActionDialog

.include <bsd.port.pre.mk>

UNAME_M_CMD=	${UNAME} -m
PLIST_SUB+=	ARCH="$$(${UNAME_M_CMD})"

post-patch-DOAS-on:
	( for SUDOF in ${_SUDOFILES}; do ${REINPLACE_CMD} -e "s@sudo \\-n@doas@g" ${WRKSRC}/$${SUDOF}; done )

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/examples/${PORTNAME}
	${MV} ${STAGEDIR}/${PREFIX}/share/doc/nscde/examples/* ${STAGEDIR}/${PREFIX}/share/examples/${PORTNAME}/

post-install-EXAMPLES-off:
	${RM} -fr ${STAGEDIR}/${PREFIX}/share/doc/nscde/examples/*

.include <bsd.port.post.mk>
