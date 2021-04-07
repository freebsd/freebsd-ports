PORTNAME=	selectwm
PORTVERSION=	0.4.1
PORTREVISION=	10
CATEGORIES=	x11-wm
MASTER_SITES=	http://ordiluc.net/selectwm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK application to let you select a window manager when starting X

USES=		gnome pkgconfig tar:bzip2
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/selectwm share/locale/fr/LC_MESSAGES/selectwm.mo \
		man/man1/selectwm.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's,-O2,${CFLAGS},g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,^CFLAGS =,CFLAGS +=,' -e 's,-O2,,' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|#define G.*DISABLE_DEPRECATED||g' \
		${WRKSRC}/src/define.h

.include <bsd.port.mk>
