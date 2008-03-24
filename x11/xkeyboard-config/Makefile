# New ports collection makefile for:	xkeyboard-config
# Date Created:				Dec 20 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xkeyboard-config
PORTVERSION=	1.2
CATEGORIES=	x11
MASTER_SITES=	http://xlibs.freedesktop.org/xkbdesc/
DISTNAME=	xkeyboard-config-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Keyboard Configuration Database

BUILD_DEPENDS=	xkbcomp:${PORTSDIR}/x11/xkbcomp

# XXX - sigh
PREFIX=		${X11BASE}

USE_BZIP2=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_GNOME=	intlhack
USE_GETTEXT=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xkb-base=${PREFIX}/share/X11/xkb \
			--with-xkb-rules-symlink=xorg
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	${MKDIR} /var/lib/xkb
	${LN} -sf /var/lib/xkb ${PREFIX}/share/X11/xkb/compiled

.include <bsd.port.mk>
