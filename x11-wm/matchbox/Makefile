# New ports collection makefile for:	matchbox
# Date created:				2002-07-14
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	matchbox
PORTVERSION=	0.3
CATEGORIES=	x11-wm
MASTER_SITES=	http://handhelds.org/~mallum/downloadables/matchbox/

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Window manager suitable for low-resolution screens

DOCS=		AUTHORS COPYING ChangeLog NEWS README TODO

CONFIGURE_ARGS=	--prefix=${PREFIX}
GNU_CONFIGURE=	yes
MAN1=		matchbox.1 mbcontrol.1 monolaunch.1 miniapm.1 minisys.1 minitime.1 minivol.1
PLIST=		${WRKDIR}/pkg-plist
USE_X_PREFIX=	yes

pre-install:
	${ECHO_CMD} bin/matchbox > ${PLIST}
.for ii in minitime minisys minivol monolaunch mbcontrol mbdock
	${ECHO_CMD} bin/${ii} >> ${PLIST}
.endfor
.for ii in defaults icon.xpm
	${ECHO_CMD} share/matchbox/${ii} >> ${PLIST}
.endfor
.for ii in mbdock themes
	cd ${WRKSRC}/data/${ii} && ${FIND} -s . -type f | \
		${CUT} -c3-999 | \
		${SED} -e 's:^:share/matchbox/${ii}/:' >> ${PLIST} \
		&& ${FIND} -d . -type d | \
		${CUT} -c3-999 | \
		${SED} -e 's:^:@dirrm share/matchbox/${ii}/:' >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
.for ii in ${DOCS}
	${ECHO_CMD} share/doc/matchbox/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm share/doc/matchbox >> ${PLIST}
.endif
	${ECHO_CMD} @dirrm share/matchbox >> ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/matchbox ${PREFIX}/bin
.for ii in minitime minisys minivol monolaunch mbcontrol
	${INSTALL_PROGRAM} ${WRKSRC}/util/${ii} ${PREFIX}/bin
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/dock/mbdock ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data/ && ${PAX} -r -w themes ${DATADIR} \
		&& ${PAX} -r -w mbdock ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif
.for ii in defaults icon.xpm
	${INSTALL_DATA} ${WRKSRC}/data/${ii} ${DATADIR}
.endfor
.for ii in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${ii} ${PREFIX}/man/man1/
.endfor

.include <bsd.port.mk>
