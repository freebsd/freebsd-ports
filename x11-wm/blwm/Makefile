# New ports collection makefile for:	blwm
# Date created:				2002-03-15
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	blwm
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	x11-wm portuguese
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Portuguese derivative of qvwm, simplified to conserve resources

RUN_DEPENDS=	xsetbg:${PORTSDIR}/x11/xloadimage

USE_AUTOCONF=	yes
USE_AUTOMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
MAN1=		blwm.1x
PLIST=		${WRKDIR}/pkg-plist
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
DOCS=		AUTHORS BUGS COPYING CREDITS FreeBSD INSTALAR LEIAME TODO

CONFIGURE_ARGS=	--prefix=${PREFIX}

do-patch:
	${PERL} -pi -e "s:wmsetbg:xsetbg:g ; \
		s:/usr/local/lib/blwm:${PREFIX}/lib/blwm:g" \
		${WRKSRC}/rc/*

pre-configure:
	cd ${WRKSRC} && \
		${ACLOCAL} && \
		${AUTOHEADER} && \
		${AUTOCONF} && \
		${AUTOMAKE}

pre-install:
	${ECHO_CMD} bin/blwm > ${PLIST}
.if !defined(NOPORTDOCS)
.for ii in ${DOCS} ChangeLog INSTALL README
	${ECHO_CMD} share/doc/blwm/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm share/doc/blwm >> ${PLIST}
.endif
	for ii in `${LS} ${WRKSRC}/images | ${GREP} xpm`; do \
		${ECHO_CMD} lib/blwm/images/$$ii >> ${PLIST}; \
	done
	for ii in `${LS} ${WRKSRC}/themes | ${GREP} -v Makefile`; do \
		${ECHO_CMD} lib/blwm/themes/$$ii >> ${PLIST}; \
	done
	for ii in `${LS} ${WRKSRC}/rc | ${GREP} -v Makefile`; do \
		${ECHO_CMD} lib/blwm/conf/$$ii >> ${PLIST}; \
	done
.for ii in /conf /images /themes /
	${ECHO_CMD} @dirrm lib/blwm${ii} >> ${PLIST}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/blwm ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${ii} ${DOCSDIR}
.endfor
.for ii in ChangeLog INSTALL README
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif
	${MKDIR}	${PREFIX}/lib/blwm/conf \
			${PREFIX}/lib/blwm/images \
			${PREFIX}/lib/blwm/themes
	${INSTALL_DATA} ${WRKSRC}/images/*xpm ${PREFIX}/lib/blwm/images
	for i in `${LS} ${WRKSRC}/rc/* | ${GREP} -v Makefile`; do \
		${INSTALL_DATA} $$i ${PREFIX}/lib/blwm/conf ; \
	done
	for i in `${LS} ${WRKSRC}/themes/* | ${GREP} -v Makefile`; do \
		${INSTALL_DATA} $$i ${PREFIX}/lib/blwm/themes ; \
	done
	${INSTALL_MAN} ${WRKSRC}/man/blwm.1x ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
