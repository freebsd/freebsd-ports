# New ports collection makefile for:	openbox
# Date created:				2002-04-28
# Whom:					trevor
# based on the blackbox port
#
# $FreeBSD$
#

PORTNAME=	openbox
PORTVERSION=	1.2.4
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://sunsite.dk/projects/openbox/

MAINTAINER=	trevor@FreeBSD.org

MAN1=		openbox.1 osetroot.1 osetbg.1

RUN_DEPENDS=	xsetbg:${PORTSDIR}/x11/xloadimage

DOCS=		AUTHORS BUGS CHANGELOG CHANGELOG.Blackbox CHANGELOG.bsetbg \
			CodingStyle INSTALL LICENSE README README.bbtools \
			README.bsetbg TODO
I10L=		C da_DK de_DE es_ES et_EE fr_FR it_IT ja_JP nl_NL pt_BR ru_RU \
			sl_SI sv_SE tr_TR zh_CN
STYLES=		artwiz bluebox cthulhain deep flux frobozz frobust nyz \
			nyzclone operation outcomes shade steelblue steelblue2 \
			the_orange trisb twice
PLIST=		${WRKDIR}/pkg-plist
USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

do-patch:
	${PERL} -pi -e \
	"s:bsetbg:osetbg:g; s:bsetroot:osetroot:g; s:Bsetroot:Osetroot:g" \
		${WRKSRC}/data/styles/* ${WRKSRC}/doc/*.1

pre-install:
	${RM} -f ${PLIST}
.for ii in osetbg osetroot openbox
	${ECHO_CMD} bin/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} share/openbox/menu >> ${PLIST}
.for ii in ${I10L}
	${ECHO_CMD} share/openbox/nls/${ii}/openbox.cat >> ${PLIST}
	${ECHO_CMD} @dirrm share/openbox/nls/${ii} >> ${PLIST}
.endfor
.for ii in POSIX US_ASCII de en en_US es fr it nl
	${ECHO_CMD} share/openbox/nls/${ii} >> ${PLIST}
.endfor
.for ii in ${STYLES}
	${ECHO_CMD} share/openbox/styles/${ii} >> ${PLIST}
.endfor
.for ii in /styles /nls /
	${ECHO_CMD} @dirrm share/openbox${ii} >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
.for ii in ${DOCS}
	${ECHO_CMD} share/doc/openbox/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm share/doc/openbox >> ${PLIST}
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/util/bsetbg ${PREFIX}/bin/osetbg
	${INSTALL_PROGRAM} ${WRKSRC}/util/bsetroot ${PREFIX}/bin/osetroot
	${INSTALL_PROGRAM} ${WRKSRC}/src/openbox ${PREFIX}/bin/
	${MKDIR} ${DATADIR}/styles
	${INSTALL_DATA} ${WRKSRC}/data/menu ${DATADIR}
.for ii in ${I10L}
	${MKDIR} ${PREFIX}/share/openbox/nls/${ii}/
	${INSTALL_DATA} ${WRKSRC}/nls/${ii}/openbox.cat \
		${PREFIX}/share/openbox/nls/${ii}/
.endfor
	cd ${PREFIX}/share/openbox/nls/ && \
		${LN} -s C POSIX && \
		${LN} -s C US_ASCII && \
		${LN} -s C en && \
		${LN} -s C en_US && \
		${LN} -s de_DE de && \
		${LN} -s es_ES es && \
		${LN} -s fr_FR fr && \
		${LN} -s it_IT it && \
		${LN} -s nl_NL nl
.for ii in ${STYLES}
	${INSTALL_DATA} ${WRKSRC}/data/styles/${ii} \
		${PREFIX}/share/openbox/styles/
.endfor
.for ii in setroot setbg
	${CP} -p ${WRKSRC}/doc/b${ii}.1 ${WRKSRC}/doc/o${ii}.1
.endfor
.for ii in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${ii} ${PREFIX}/man/man1/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
