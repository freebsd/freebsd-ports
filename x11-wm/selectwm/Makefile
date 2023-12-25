PORTNAME=	selectwm
PORTVERSION=	0.4.1
PORTREVISION=	12
CATEGORIES=	x11-wm
MASTER_SITES=	https://ordiluc.net/selectwm/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Select a window manager when starting X11
WWW=		https://ordiluc.net/selectwm/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk20

PLIST_FILES=	bin/selectwm share/locale/fr/LC_MESSAGES/selectwm.mo \
		man/man1/selectwm.1.gz

post-patch:
	@${REINPLACE_CMD} -e '/^AM_CFLAGS = /s,-s -O2 -Wall ,,' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/^#define G.*DISABLE_DEPRECATED/d' \
		${WRKSRC}/src/define.h
	@${REINPLACE_CMD} -e 's,getline (,_${PORTNAME}_local_&,' \
		${WRKSRC}/src/options.c

.include <bsd.port.mk>
