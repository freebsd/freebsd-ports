# Created by: ijliao
# $FreeBSD$

PORTNAME=	wmdrawer
PORTVERSION=	0.10.5
PORTREVISION=	10
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://people.easter-eggs.org/~valos/wmdrawer/ \
		http://www.sourcefiles.org/Utilities/Desktops/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp which provides a drawer to launch applications

LICENSE=	GPLv2+

USES=		gmake pkgconfig
USE_GNOME=	gdkpixbuf2
MAKE_ENV=	USE_GDKPIXBUF2=1

SUB_FILES=	pkg-message

PORTDOCS=	AUTHORS ChangeLog INSTALL README TODO wmdrawerrc.example
PLIST_FILES=	bin/wmdrawer man/man1/wmdrawer.1x.gz %%DATADIR%%/beastie.png

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}| ; \
		 s|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/wmdrawerrc.example
	@${REINPLACE_CMD} -e \
		's|^\(CC\)|#\1| ; \
		 s|^\(DESTDIR\)|#\1| ; \
		 s|^\(PREFIX\)|#\1| ; \
		 s|^\(USE_\)|#\1| ; \
		 s|^\(CFLAGS\) = -O3|\1 +=| ; \
		 s|^\(LDFLAGS\) =|\1 +=| ; \
		 s|/usr/X11R6|$${LOCALBASE}| ; \
		 s|strip|true| ; \
		 s|$$(INSTALL) -m 755|$${BSD_INSTALL_PROGRAM}| ; \
		 s|$$(INSTALL) -m 644|$${BSD_INSTALL_DATA}| ; \
		 s|COPYING|| ; \
		 /INSTALL/s| \($$(PREFIX)\)| $$(DESTDIR)\1| ; \
		 /INSTALL/s| \($$(MANDIR)\)| $$(DESTDIR)\1| ; \
		 /INSTALL/s| \($$(DOCDIR)\)| $$(DESTDIR)\1|' ${WRKSRC}/Makefile

post-build:
	@(cd ${WRKDIR} && uudecode ${FILESDIR}/logo-beastie.png.uue)

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKDIR} && ${INSTALL_DATA} logo-beastie.png \
		${STAGEDIR}${DATADIR}/beastie.png)

.include <bsd.port.mk>
