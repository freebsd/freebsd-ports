# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	simplestroke
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
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
MAKE_ARGS=	INSTALL_MAN="${INSTALL_MAN}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

PLIST_FILES=	"${_MAYBE_SUID}bin/simplestroke" \
		share/man/man1/simplestroke.1.gz

OPTIONS_DEFINE=		SUID
OPTIONS_DEFAULT=	SUID
OPTIONS_SUB=		yes

SUID_DESC=	Install with setuid bit for opening evdev(4) devices

SUID_VARS=	_MAYBE_SUID="@(,,4755) "
SUID_VARS_OFF=	_MAYBE_SUID=""

.include <bsd.port.mk>
