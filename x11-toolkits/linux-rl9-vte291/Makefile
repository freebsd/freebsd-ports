PORTNAME=	vte291
PORTVERSION=	0.64.2
DISTVERSIONSUFFIX=	-2.el9
CATEGORIES=	x11-toolkits linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Terminal widget with accessibility and I18N support (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://wiki.gnome.org/Apps/Terminal/VTE

LICENSE=	LGPL3+ MIT
LICENSE_COMB=	multi

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	atk cairo fribidi gdkpixbuf2 gnutls gtk3 icu pango systemd-libs
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

DESCR=		${PORTSDIR}/${PKGCATEGORY}/vte3/pkg-descr

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
