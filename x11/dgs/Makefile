# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$

PORTNAME=	dgs
PORTVERSION=	0.5.9.1
PORTREVISION=	13
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	../old-gnu/dgs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display ghostscript system

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff

MAKE_JOBS_UNSAFE=	yes

USE_GHOSTSCRIPT_RUN=	yes
USE_XORG=	xt sm ice xext x11
USE_GNOME=	glib12
USES=		gmake libtool makeinfo
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-0.5.9

pre-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} \
		${REINPLACE_CMD} -e 's|manm|mann|g'

post-patch:
	${REINPLACE_CMD} -e 's|echo aout|echo elf|' \
	-e 's|freebsd2\*)|freebsd2.\*)|' -e 's|freebsd1\*)|freebsd1.\*)|' \
		${WRKSRC}/DPS/ltconfig
	${REINPLACE_CMD} -e 's,@prefix@,$$(DESTDIR)@prefix@,g' \
		-e 's,@mandir@,$$(DESTDIR)@mandir@,g' \
		${WRKSRC}/gs/unix-gcc.mak.in

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dgs-config ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/dpsnx.agent ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/dpsnx.agent.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
