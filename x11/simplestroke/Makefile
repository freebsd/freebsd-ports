# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	simplestroke
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	x11

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Detect mouse gestures

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	t6

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	LDFLAGS="${LDFLAGS}" \
		PREFIX="${PREFIX}"
MAKE_ARGS=	INSTALL_LIB="${INSTALL_LIB}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

PLIST_FILES=	"${_MAYBE_SUID}bin/simplestroke" \
		"${_MAYBE_SUID}bin/simplestroke-daemon" \
		man/man1/simplestroke-daemon.1.gz \
		man/man1/simplestroke.1.gz

OPTIONS_DEFINE=		SUID X11
OPTIONS_DEFAULT=	SUID X11
OPTIONS_SUB=		yes

SUID_DESC=	Install with setuid bit for opening evdev(4) devices
X11_DESC=	XTEST based mouse tracker

SUID_VARS_OFF=	_MAYBE_SUID=""
SUID_VARS=	_MAYBE_SUID="@(,,4755) "

X11_USES=	xorg
X11_USE=	XORG=x11,xtst

pre-configure-X11-off:
	@${ECHO_CMD} HAVE_X11=0 > ${WRKSRC}/configure.local

.include <bsd.port.mk>
